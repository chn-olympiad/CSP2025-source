#include <cstdio>
#include <algorithm>
bool cmp(int a,int b) {return a>b;}
int n,m,a,b[105],c[105][105],s,top=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;++i){
		scanf("%d",&a);
		b[i]=a;
	}
	a=b[1];
	std::sort(b+1,b+1+n*m,cmp);
	for (int i=1;i<=m;++i){
		if (i&1){
			for (int j=1;j<=n;++j){
				c[j][i]=b[top++];
			}
		} else{
			for (int j=n;j>=1;--j){
				c[j][i]=b[top++];
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			if (c[i][j]==a){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
