#include<cstdio>
#include<algorithm>
using namespace std;
inline bool cmp(int x,int y) { return x>y; }
int n,m,a[1001],g[20][20],ansx,ansy,csa;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",&a[i]);
	csa=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;++i) {
		if(i%2) 
			for(int j=1;j<=n;++j) g[j][i]=a[(i-1)*n+j];
		else 
			for(int j=n;j>=1;--j) g[j][i]=a[(i-1)*n+(n-j+1)];
	}
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=m;++j) 
			if(g[i][j]==csa) { ansx=j,ansy=i; break; }
	printf("%d %d",ansx,ansy);
	return 0;
}
