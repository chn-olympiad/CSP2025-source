#include<bits/stdc++.h>
using namespace std;
int n,m,ny,nx,v,o;
int a[10000005];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	o=a[0];
	for(int i=0;i<n*m;i++)
	{
		int ans;
		ans=a[i];
			for(int j=i;j<=n*m;j++)
		{
			if(a[j]>ans)
			{
				ans=a[j];
				a[j]=a[i];
			}	
			a[i]=ans;
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==o)
			v=i;
	}
	ny=v/n+1;
	nx=v%n;
	if(ny%2==0)
		cout<<ny<<" "<<m-nx;
	else
		cout<<ny<<" "<<nx+1;
}
