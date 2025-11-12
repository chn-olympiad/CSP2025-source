#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t,r,cnt=0,l,s;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		if(i==0)
		{
			cin>>r;
		}
		else
		{
			cin>>t;
			if(t>r)
			{
				cnt++;
			}
		}
	}
	l=cnt/n;
	if(l%2==0)
	{
		s=cnt%n;
		cout<<l+1<<" "<<s+1;
	}
	else
	{
		s=cnt%n;
		cout<<l+1<<" "<<m-s;
	}
	return 0;
}
