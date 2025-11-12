#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,ans;
int a[1007];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	int x=cnt%m;
	int y=cnt/m;
	if(x==0)
		cout<<y<<" "<<n;
	else
	{
		if(y%2==0)
		{
			cout<<y+1<<" "<<x;
		}
		else
		{
			cout<<y+1<<" "<<n-x+1;
		}
	}
	return 0;
}
