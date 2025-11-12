#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,y=0;
int a[105];
int s[15][15];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m;j++)
		{
			if(a[j]<a[j+1]) {
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
		{
			if(a[y]==x)
			{
				cout<<i<<endl;
				cout<<j<<endl;
				return 0;
			}
			y++;		
		}
		}
		else{
			for(int j=1;j<=n;j++)
		{
			if(a[y]==x)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			y++;		
		}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
