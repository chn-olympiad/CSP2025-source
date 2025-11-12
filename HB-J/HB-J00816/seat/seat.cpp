#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[11][11],e;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				e++;
				b[i][j]=a[e];
				if(b[i][j]==ans)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		if(j%2==0)
		{
			for(int i=n;i>=1;i--)
			{
				e++;
				b[i][j]=a[e];
				if(b[i][j]==ans)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}

	return 0;
}			
