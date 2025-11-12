#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+10;
int n,m,t,tx,ty,cnt,flag,a[N];
bool cmp(int x,int y) {return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	tx=1,ty=0,flag=1;
	while(1)
	{
		ty+=flag;
		cnt++;
		if(ty>n)
		{
			tx++;
			ty=n;	
			flag=-1;
		} 
		else if(ty<1)
		{
			tx++;
			ty=1;
			flag=1;
		}
		if(a[cnt]==t)
		{
			printf("%d %d",tx,ty);
			break;
		}
	}
	return 0;
}
