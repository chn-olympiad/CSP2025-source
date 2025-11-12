#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=0,x;
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++)
	{
		int q;
		cin>>q;
		if(q>x)
		{
			t++;
		}
	}
	int h=(t+1)/n;
	if((t+1)%n==0)
	{
		if(h%2==0)
		{
			cout<<h<<" "<<1;
			return 0;
		}
		else
		{
			cout<<h<<" "<<m;
			return 0;
		}
	}
	int l=(t+1)%n;
	if((h+1)%2==0)
	{
		cout<<h+1<<" "<<m-l+1;
	}
	else
	{
		cout<<h+1<<" "<<l;
	}
	return 0;
}