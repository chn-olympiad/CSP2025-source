#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main()
{
    	freopen("seat.in","r",stdin);
    	freopen("seat.out","w",stdout);
	int n,m;
	int i,j;
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{   
			cin>>a[i][j];
			a[i][j]=0;
		}
	}
	for(int i=0;i<=100;i++)
	{
		a[i][j]++;
		if(x=a[i][j])
		{
			cout<<a[i][j];
		}
	}
	return 0;
}