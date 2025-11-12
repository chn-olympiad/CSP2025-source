#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
using namespace std;
namespace Yukina{
	inline int read(){
		int ans=0,w=1;
		char ch=getchar();
		while(ch<48||ch>57){
			if(ch=='-')w=-1;
			ch=getchar();
		}
		while(ch>=48&&ch<=57){
			ans=(ans<<1)+(ans<<3)+ch-48;
			ch=getchar();
		}
		return w*ans;
	}
	int n,m;
	const int mod=998244353;
	int f[(1<<18)+5][20][20];
	char ch[505];
	int c[505];
	int main(){
		n=read(),m=read();
		scanf("%s",ch+1);
		for(int i=1;i<=n;i++)c[i]=read();
		if(n<=18){
			f[0][0][0]=1;
			for(int s=0;s<(1<<n);s++){
				int cnt=0;
				for(int i=1;i<=n;i++)if(s&(1<<i-1))++cnt;
				for(int i=0;i<=cnt;i++){
					for(int j=0;j<=cnt;j++){
						if(!f[s][i][j])continue;
						for(int k=1;k<=n;k++){
							if(s&(1<<k-1))continue;
							if(ch[cnt+1]=='0'||j>=c[k]){
								f[s|(1<<k-1)][i][j+1]=(f[s|(1<<k-1)][i][j+1]+f[s][i][j])%mod;
							}else{
								f[s|(1<<k-1)][i+1][j]=(f[s|(1<<k-1)][i+1][j]+f[s][i][j])%mod;
							}
						}
					}
				}
			}
			ll ans=0;
			for(int i=m;i<=n;i++){
				for(int j=0;j<=n;j++)ans=(ans+f[(1<<n)-1][i][j])%mod;
			}
			cout<<ans<<"\n";
		}else{
			ll ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return Yukina::main();
}
//400MB
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

