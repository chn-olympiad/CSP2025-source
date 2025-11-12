#include<bits/stdc++.h>
using namespace std;

const int N=500;

int a[N][N];
int b[N];
int n,m;
int ans;

bool cmp(int a,int b)
{
	return b<a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	

	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];	
	}
	
	ans=b[1];

	sort(b+1,b+n*m+1,cmp);

	int cnt=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[j][i]=b[cnt];		
			cnt++;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==ans)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}	
	}

	return 0;
}

