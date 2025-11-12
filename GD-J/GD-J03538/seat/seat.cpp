#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nw=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		
	}
	nw=a[1];
	sort(a+1,a+n*m+1);
	int nx=1,ny=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==nw)
		{
			cout<<ny<<" "<<nx<<'\n';
			break;
		}
		else
		{
			if(nx==n&&ny%2==1)
			{
				nx=n;
				ny++;
			}
			else if(nx==1&&ny%2==0)
			{
				nx=1;
				ny++;
			}
			else
			{
				if(ny%2==0)
				{
					nx--;
				}
				else
				{
					nx++;
				}
			    
			}
		}
	}
}
