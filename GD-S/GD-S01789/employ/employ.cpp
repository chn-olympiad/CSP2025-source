#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
const int N=510,K=1<<18;
int n,m,f[K][N];
int c[N];
int inv[N],fac[N];
string s;
int qpow(int x,int b){
	int ans=1;
	while(b>0){
		if(b&1)
			ans=1ll*ans*x%MOD;
		x=1ll*x*x%MOD;
		b>>=1;
	}
	return ans;
}
void init(){
	inv[0]=fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n]=qpow(fac[n],MOD-2);
	for(int i=n-1;i;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%MOD;
}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	init();
//	cout<<s<<"\n";
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==n){
		int flag=1;
		for(auto now:s)
			flag&=(now-'0');
		if(!flag)cout<<"0\n";
		else{
			int sum=0,ans=1;
			for(int i=1;i<=n;i++)
				sum+=(c[i]==0);
			for(int i=sum+1;i<=n;i++)
				ans=1ll*ans*(i-sum)%MOD;
			for(int i=1;i<=sum;i++)
				ans=1ll*ans*i%MOD;
			cout<<ans<<"\n";
		}
		return 0;
	}else if(n<=18){
		f[0][0]=1;
		for(int j=0;j<(1<<n)-1;j++){
			for(int i=1;i<=n;i++){
				if((j>>(i-1))&1)continue;
				int d=0;
				for(int k=0;k<n;k++)
					d+=((j>>k)&1);
				int now=s[d]-'0';
				for(int k=0;k<=n;k++){
					(f[j|(1<<(i-1))][k+(now&&(c[i]>d-k))]+=f[j][k])%=MOD;
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
			(ans+=f[(1<<n)-1][i])%=MOD;
		cout<<ans<<"\n";
	}
	return 0;
}
