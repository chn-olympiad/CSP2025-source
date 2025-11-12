# include <cstdio>
using namespace std;
int n,m,a[100007];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1]) ans++;
	}
	int x=1,y=1;
	while(ans>0)
	{
		if(x%2==1&&y==n) x++;
		else if(x%2==0&&y==1) x++;
		else if(x%2==1) y++;
		else y--;
		ans--;
	}
	printf("%d %d\n",x,y);
	return 0;
}
