#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int p;
int rs;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	cin>>k;
	p=k;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>k;
		if(k>p)
		++rs;
	}
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
		    {
		    	if(rs)
		    	--rs;
		    	else
		    	{
		    		cout<<j<<" "<<i;
		    		return 0;
				}
		    }
		}
		else
		{
			for(int i=n;i>=1;i--)
		    {
		    	if(rs)
		    	--rs;
		    	else
		    	{
		    		cout<<j<<" "<<i;
		    		return 0;
				}
		    }
		}
	}
	return 0;
}