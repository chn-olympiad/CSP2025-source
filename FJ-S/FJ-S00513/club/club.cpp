#include <bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
int T,n;
const int maxn=35;
int f[maxn][maxn][maxn][maxn];
int a[maxn][4];
inline int read()
{
	re int x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') w=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*w;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		memset(f,0xcf,sizeof(f));
		n=read();
		for(re int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		f[1][1][0][0]=a[1][1];
		f[1][0][1][0]=a[1][2];
		f[1][0][0][1]=a[1][3];
			
		for(re int i=2;i<=n;i++){
			for(re int j=0;j<=i;j++){
				for(re int k=0;k<=i-j;k++){
					int p=i-j-k;
					if (j==0 && k==0){
						f[i][j][k][p]=max(f[i][j][k][p],f[i-1][j][k][p-1]+a[i][3]);
					}
					else if (j==0 && k >0){
						f[i][j][k][p]=max(f[i][j][k][p],max(f[i-1][j][k-1][p]+a[i][2],f[i-1][j][k][p-1]+a[i][3]));
					}
					else if (p==0){
						f[i][j][k][p]=max(f[i][j][k][p],max(f[i-1][j-1][k][p]+a[i][1],f[i-1][j][k-1][p]+a[i][2]));
					}
					else  f[i][j][k][p]=max(max(f[i-1][j-1][k][p]+a[i][1],f[i][j][k][p]),max(f[i-1][j][k-1][p]+a[i][2],f[i-1][j][k][p-1]+a[i][3]));
				}
			}
		}
		int ans=0;
		for(re int j=0;j<=n/2;j++){
			for(re int k=0;k<=n/2;k++){
				int p=n-j-k;
				if (p>n/2) continue;
				ans=max(f[n][j][k][p],ans);
			}
		}
		printf("%d\n",ans);
	}
}
