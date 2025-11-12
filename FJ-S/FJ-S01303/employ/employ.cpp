#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1<<18,mod=998244353;
int f[N][25],a[N],b[N],n,m;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
inline int get(int x){
	int ans=0;
	while(x) ans++,x&=x-1;
	return ans;
}
main(){
//	freopen("employ2.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) scanf("%1lld",a+i);
	for (int i=1;i<=n;i++) b[i]=read();
	if (n==m){
		int ans=0;
		for (int i=1;i<=n;i++) ans+=a[i];
		if (ans^n) return 0&puts("0");
		for (int i=1;i<=n;i++)
			if (b[i]==0) return 0&puts("0");
		ans=1;
		for (int i=1;i<=n;i++) ans=ans*i%mod;
		cout <<ans;
		return 0;
	}
	f[0][0]=1;
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<=n;j++){
			for (int k=1;k<=n;k++) if ((i>>(k-1))&1^1){
				int x=get(i)-j;
				if (x>=b[k]||a[get(i)+1]==0) f[i|(1<<(k-1))][j]=(f[i|(1<<(k-1))][j]+f[i][j])%mod;
				else f[i|(1<<(k-1))][j+1]=(f[i|(1<<(k-1))][j+1]+f[i][j])%mod;
			}
		}
	int ans=0;
	for (int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	cout <<ans;
	return 0;
}

