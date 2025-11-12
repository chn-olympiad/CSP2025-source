#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int idx=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[idx]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				idx++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[idx]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				idx++;
			}
		}
	}
	return 0;
}
