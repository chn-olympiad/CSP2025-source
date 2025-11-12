#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int s;
int h;
bool cmp(int x,int y)
{
	return x>y;
}
int x=1,y=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x&1)y++;
		else y--;
//		cout<<x<<' '<<y<<'\n';
		if(a[i]==s)
		{
			cout<<x<<' '<<y;
			break;
		}
//		if(x==1)continue;
		if((y==n&&x%2==1)||(y==1&&x%2==0))
		{
			x++;
			if(x&1)y--;
			else y++;
		}
	}
	return 0;
}
