#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> scs(n*m);
	for(int i=0;i<n*m;i++)
	{
		cin>>scs[i];
	}
	int tgt=scs[0];
	vector<vector<int>> seat(m,vector<int>(n,0));
	sort(scs.begin(),scs.end());
	reverse(scs.begin(),scs.end());
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			int h;
			if(j%2==0)
			h=i;
			else
			h=n-i-1;
			seat[j][h]=scs[i+j*n];
		}
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(seat[j][i]==tgt)
			{
				cout<<j+1<<" "<<i+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
