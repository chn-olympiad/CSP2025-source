#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N],b[N][N],c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0)c=a[i];
	}
	sort(a,a+n*m,cmp);
	int z=1,y=1;
	for(int i=0;i<n*m;i++)
	{
		int x=i/(n)+1;//x是列 y是行 
		if(a[i]==c)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(x<=n&&y<=m)
		{
			y=y+z;
		}
		if(y>n)
		{
			y--;
			z=-1;
		}
		if(y<1)
		{
			y++;
			z=1;
		}
	}
	return 0;
}
