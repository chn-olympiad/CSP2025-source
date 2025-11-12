#include<bits/stdc++.h>
using namespace std;
const int N = 505,mod=998244353;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,c[N],f[1<<18][19],jie[N],inv[N],cnt[N],p[N],num,sum[N],dp[N];
char s[N];
inline int A(int n,int m){
	return jie[n]*1ll*inv[n-m]%mod;
}
inline int C(int n,int m){
	return jie[n]*1ll*inv[m]%mod*inv[n-m]%mod;
}
vector<int>v[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i = 1;i<=n;i++)c[i]=read();
	if(n<=18){
		f[0][0]=1;
		for(int i = 0;i<(1<<n);i++){
			for(int j = 0;j<n;j++){
				if(!f[i][j])continue;
				int w = __builtin_popcount(i);
				for(int k = 1;k<=n;k++){
					if(!(i&(1<<k-1))){
						if(s[w+1]=='0' || c[k] <= w-j)f[i|(1<<k-1)][j]=(f[i|(1<<k-1)][j]+f[i][j])%mod;
						else f[i|(1<<k-1)][j+1]=(f[i|(1<<k-1)][j+1]+f[i][j])%mod;
					}
				}
			}
		}
		int ans=0;
		for(int i = m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i = 1;i<=n;i++){
			if(c[i]==0||s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		for(int i = 1;i<=n;i++)ans=1ll*ans*i%mod;
		cout<<ans;
		return 0;
	}
	jie[0]=jie[1]=inv[0]=inv[1]=1;
	for(int i = 2;i<=n;i++)jie[i]=jie[i-1]*1ll*i%mod,inv[i]=inv[mod%i]*1ll*(mod-mod/i)%mod;
	for(int i = 2;i<=n;i++)inv[i]=inv[i-1]*1ll*inv[i]%mod;
	for(int i = 1;i<=n;i++)cnt[c[i]]++;
	int ans=0;
	if(m==1){
		for(int i = 1;i<=n;i++){
			if(s[i]=='0')continue;
			int c = 0;
			for(int j = i;j<=n;j++)c+=cnt[j];
			int sum=c,w=0,gg=n-1;
			for(int j = 1;j<i;j++){
				w+=cnt[j-1];
				if(s[j]=='1'){
					sum=1ll*sum*w%mod;
					w--;gg--;
				}
			}
			ans=(ans+1ll*sum*jie[gg])%mod;
		}
		cout<<ans;
		return 0; 
	}
	for(int i = 1;i<=n;i++)if(s[i]=='1')p[++num]=i;
	sum[0]=cnt[0];
	for(int i = 1;i<=n;i++)sum[i]=sum[i-1]+cnt[i];
	for(int i = 1;i<(1<<num);i++){
		if(__builtin_popcount(i)<m)continue;
		int now = 0;
		for(int j = 0;j<=num;j++)dp[j]=0;
		dp[0]=1;
		for(int j = 0;j<=n;j++)v[j].clear();
		int sur=0;
		for(int j = 1;j<=num;j++){
			if(i&(1<<j-1)){
				v[p[j]-sur-1].push_back(1);
				sur++;
			}
			else v[p[j]-sur].push_back(0);
		}
		sur=0;
		int num1=0;
//		for(int j = 0;j<=n;j++){
//			for(int x: v[j]){
//				if(!x){
//					for(int k = 0;k<=num1;k++){
//						if(j-1>=0)dp[k]=1ll*dp[k]*(sum[j-1] - sur - k)%mod;
//					}
//					sur++;
//				}
//			}
//			for(int k1 = num1;k1>=0;k1--){
//				for(int k2 = k1+1;k2<=num1&&k2-k1<=cnt[j];k2++){
//					dp[k2]=(dp[k2] + 1ll*dp[k1]*C(num1 - k1,k2 - k1)%mod*A(cnt[j],k2-k1))%mod;
//				} 
//			}
//			for(int x:v[j]){
//				if(x)num1++;
//			}
//		}
		for(int l = 0,r;l<=n;l=r+1){
			r=l;
			if(v[l].size()){
				int j = l;
				for(int x: v[j]){
					if(!x){
						for(int k = 0;k<=num1;k++){
							if(j-1>=0)dp[k]=1ll*dp[k]*(sum[j-1] - sur - k)%mod;
						}
						sur++;
					}
				}
				for(int k1 = num1;k1>=0;k1--){
					for(int k2 = k1+1;k2<=num1&&k2-k1<=cnt[j];k2++){
						dp[k2]=(dp[k2] + 1ll*dp[k1]*C(num1 - k1,k2 - k1)%mod*A(cnt[j],k2-k1))%mod;
					} 
				}
				for(int x:v[j]){
					if(x)num1++;
				}
				continue;
			}
			while(r<=n&&v[r].size()==0)r++;
			r--;
			int ss = sum[r];
			if(l)ss-=sum[l-1];
			for(int k1 = num1;k1>=0;k1--){
				for(int k2 = k1+1;k2<=num1&&k2-k1<=ss;k2++){
					dp[k2]=(dp[k2] + 1ll*dp[k1]*C(num1 - k1,k2 - k1)%mod*A(ss,k2-k1))%mod;
				} 
			}
		}
		ans=(ans+dp[num1]*1ll*jie[n-num])%mod;
	} 
	cout<<ans;
	return 0;
}


