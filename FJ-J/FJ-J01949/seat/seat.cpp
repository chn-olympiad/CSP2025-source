#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>b[i];
	}
	int ans=b[1];
	if(n==1&&m==1)
	{
		cout<<n<<' '<<m<<endl;
		return 0;
	}
	sort(b+1,b+n*m+1,greater<int>());
	if(n==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(b[i]==ans)
			{
				cout<<1<<' '<<i<<endl;
			}
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(b[i]==ans)
			{
				cout<<i<<' '<<1<<endl; 
			}
		}
	}
	return 0; 
 } 
