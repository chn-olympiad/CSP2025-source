#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
pair<int,int>a[200010];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{	
		cin>>a[i].first;
		a[i].second=i;		
	}
	sort(a+1,a+n*m+1,greater<pair<int,int>>());
	for(int i=1;i<=n*m;i++)
		if(a[i].second==1)
		{
			if(((i-1)/n+1)%2==0)
				cout<<(i-1)/n+1<<' '<<n-((i-1)%n+1)+1;
			else
				cout<<(i-1)/n+1<<' '<<((i-1)%n+1);
			return 0;
		}
	return 0;
}

