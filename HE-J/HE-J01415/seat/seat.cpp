#include <bits/stdc++.h>
using namespace std;
int a[25][25];
int b[150];
int ans,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i==1)ans=b[i];
	}
	//cout<<ans;
	sort(b+1,b+n*m+1);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[j][i]=b[n*m-x];
			x++;
			if(a[j][i]==ans)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}

	return 0;
}


