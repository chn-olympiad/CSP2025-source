#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,c,r,f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s)
		{
			f=i;
			break;
		}
	if(f%n) c=f/n+1,f%=n;
	else c=f/n,f=n;
	if(c&1) r=f;
	else r=n-f+1;
	printf("%d %d",c,r);
	return 0;
}
