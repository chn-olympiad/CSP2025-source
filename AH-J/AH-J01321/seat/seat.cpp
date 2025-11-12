#include<bits/stdc++.h>
using namespace std;
int a[1000],b[15][15];
bool cmp(int x,int y)
{
	return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int x=1,y=1;
	int k=a[1],d=1;
	sort(a+1,a+n*m+1,cmp);
	int f=0;
	while(y<=m)
	{
		//cout<<y<<" "<<x<<'\n';
		if(a[d]==k)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(f==0)
		x++;
		else
		x--;
		
		if(x>n&&f==0)
		{
			f=1;
			x=n;
			y++;
		}
		else if(x<=0&&f==1)
		{
			f=0;
			x=1;
			y++;
		}
		b[x][y]=a[d];
		d++;
	}
	return 0;
}
