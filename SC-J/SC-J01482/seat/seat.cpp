#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b,c[105][105],r;
void search(int x,int y)
{
	if(b==1) 
	{
		cout<<x<<" "<<y;
		return;
	}
	b--;
	if((y==n&&x%2==1)||(y==1&&x%2==0))
	{
		search(x+1,y);
	}
	else if(x%2==1)
	{
		search(x,y+1);
	}
	else if(x%2==0)
	{
		search(x,y-1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			b=n*m-i+1;
			break;
		}
	}
	search(1,1);
	return 0;
}