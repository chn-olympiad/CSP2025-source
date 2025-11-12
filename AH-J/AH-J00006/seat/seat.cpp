#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				if(a[(i-1)*n+j]==ans)
					cout<<i<<" "<<j;
		}
		else
		{
			for(int j=1;j<=n;j++)
				if(a[(i-1)*n+j]==ans)
					cout<<i<<" "<<n-j+1;
		}
	}
	return 0;
}
