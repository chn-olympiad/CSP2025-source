#include<cstdio>
#include<algorithm>

int n=1,m,a[120];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int t=a[1],x;
	std::sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==t) x=i;
	int c=(x-1)/n+1,r=x-(c-1)*n;
	printf("%d %d",c,c%2==1?r:n-r+1);
	return 0;
}
