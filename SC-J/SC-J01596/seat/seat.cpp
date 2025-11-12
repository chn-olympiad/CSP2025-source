#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],temp,num,x=1,y=1;
bool flag=1;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	temp=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==temp)
		{
			num=n*m-i+1;
			break;
		}
	}
	for(int i=1;i<=num;i++)
	{
		if(i==num)
		{
			cout<<y<<' '<<x<<'\n';
			exit(0);
		}
		if(x==n&&flag==1)
			y++,x=n+1,flag=0;
		if(x==1&&flag==0)
			y++,x=0,flag=1;
		if(flag)	x++;
		else		x--;
	}
	return 0;
}
