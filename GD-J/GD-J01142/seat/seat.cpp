#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6;
int n,m,k,a[maxn];
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,[](int sx,int sy){return sx>sy;});
	for(int i=1;i<=n*m;i++)
		if(a[i]==k)
		{
			k=i;
			break;
		}
	x=(k-1)/n+1;
	k-=(x-1)*n;
	if(x&1)y=k;
	else y=n-k+1;
	printf("%d %d",x,y);
	return 0;
}
