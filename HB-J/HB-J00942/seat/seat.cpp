#include <bits/stdc++.h>
using namespace std;
int n,m;
int s,r;
int k=1;
int x=1,y=1,flag=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>r;
		if(r>s) k++;
	}
	for(int i=1;i<=k-1;i++)
	{
		if(flag==1&&x==n)
		{
			y++;
			flag=0;
			continue;
		}
		else if(flag==0&&x==1)
		{
			y++;
			flag=1;
			continue;
		}	
		if(flag==1) x++;
		else x--;
	}
	cout<<y<<" "<<x;
	return 0;
}
