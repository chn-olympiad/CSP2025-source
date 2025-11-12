#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int a[100][100]={0};
	int a1[n]={0};
	int b[k][n+1]={0};
	for(int i=0;i<m;i++)
	{
		int j,l,mo1;
		cin>>j>>l>>mo1;
		a[i][j]=mo1;
		a1[i]=mo1;
	}
	
	for(int i=0;i<k;i++)
	{
		cin>>b[i][0];
		for(int f=1;f<=n;f++)
		{
			cin>>b[i][f];ans+=b[i][f];
		}
		
	}
	cout<<ans;
	return 0;
}
