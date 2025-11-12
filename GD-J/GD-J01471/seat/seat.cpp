#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N],num;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(i%n==1)
		{
			x++;
		}
		else if(x%2==1)
		{
			y++;
		}
		else
		{
			y--;
		}
		if(a[i]==num)
		{
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
