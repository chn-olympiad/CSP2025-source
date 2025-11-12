#include<bits/stdc++.h>
using namespace std;
long long a[110];
long long n,m,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		if(a[i*n]<r)
		{
			cout<<i<<" ";
			for(int j=1;j<=n;j++)
			{
				if(a[i*n-j]==r)
				{
					if(i%2==0) cout<<j+1;
					else cout<<n-j;
					return 0;
				}
			}
		}
		else if(a[i*n]==r)
		{
			cout<<i<<" ";
			if(i%2==0) cout<<1;
			else cout<<n;
			return 0;
		}
	}
	return 0;
}
