#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void write(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		write(k/10);
	putchar(k%10+'0');
}
const int mod=998244353;
int n,m,c[505],dp[19][1<<18][19],ans,jc[505],f[505][505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+n+1);
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=1ll*jc[i-1]*i%mod;
	}
	if(n<=18){
		dp[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++){
				if(__builtin_popcount(j)!=i)
					continue;
				for(int k=0;k<=i;k++){
					for(int p=1;p<=n;p++){
						if(!((j>>(p-1))&1))
							dp[i+1][j|(1<<(p-1))][k+(c[p]>i-k&&s[i+1]=='1')]=(dp[i+1][j|(1<<(p-1))][k+(c[p]>i-k&&s[i+1]=='1')]+dp[i][j][k])%mod;
					}
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans=(ans+dp[n][(1<<n)-1][i]);
		}
		write(ans);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				write(0);
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=1ll*ans*i%mod;
		}
		write(ans);
		return 0;
	}
	if(m==1){
		int num=0,l=0,v=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')
				continue;
			while(l<n&&c[l+1]<=i-1){
				l++;
			}
			ans=(1ll*v*jc[n-num-1]%mod*(n-l)+ans)%mod;
			v=1ll*v*(l-num)%mod;
			num++;
		}
		write(ans);
		return 0;
	}
	return 0;
}