#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int> a;
	int n,m,R,x;
	cin>>n>>m;
	x=n*m-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int t;
			cin>>t;
			if(i==0&&j==0)
			{
				R=t;
			}
			a.push_back(t);
		}
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[x]==R)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				
				x--;
			}
		} 
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[x]==R)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				x--;
			}
		}
	}
	return 0;
}
