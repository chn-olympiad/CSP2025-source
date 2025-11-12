#include <bits/stdc++.h>
using namespace std;
int n,m,r,a[107],nowx=1,nowy=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(i==1)
		{
			nowx=1;
			nowy=1;
		}
		else if(nowy%2==1 && nowx==n)
		{
			nowy++;
		}
		else if(nowy%2==0 && nowx==1)
		{
			nowy++;
		}
		else if(nowy%2==1)
		{
			nowx++;
		}
		else
		{
			nowx--;
		}
		if(a[i]==r)
		{
			cout<<nowy<<' '<<nowx;
			return 0;
		}
	}
}
