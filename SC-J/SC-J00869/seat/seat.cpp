#include<bits/stdc++.h>
using namespace std;
int a[10001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			if(a[i*n]<=k)
			{
				for(int j=1;j<=n;j++)
					if(a[n*(i-1)+j]==k) cout<<i<<" "<<j;
				break;
			}
		}
		else
		{
			if(a[i*n]<=k)
			{
				for(int j=n;j>=1;j--)
					if(a[n*(i-1)+j]==k) cout<<i<<" "<<n-j+1;
				break;
			}
		}
	}
	return 0;
}