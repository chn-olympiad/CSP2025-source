#include<bits/stdc++.h>
# define Maxn 15
using namespace std;
int n,m,a[Maxn*Maxn],rk;
int pos[Maxn][Maxn],h[Maxn*Maxn],w[Maxn*Maxn],cnt;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	scanf("%d",&a[i]),rk+=(a[i]>=a[1]);
	for(int j=1;j<=m;j++) {
		if(j%2) {
			for(int i=1;i<=n;i++)
			pos[i][j]=++cnt,h[cnt]=i,w[cnt]=j;
		}
		else {
			for(int i=n;i>=1;i--)
			pos[i][j]=++cnt,h[cnt]=i,w[cnt]=j;
		}
	}
	printf("%d %d\n",w[rk],h[rk]);
	return 0;
}
