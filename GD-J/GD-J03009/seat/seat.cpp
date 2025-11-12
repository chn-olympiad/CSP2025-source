#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105],len=0;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int i=1;i<=m;i++)cin>>a[++len];
	int sc=a[1];
	sort(a+1,a+len+1);
	int id=lower_bound(a+1,a+len+1,sc)-a;
	id=len-id+1;
	for(int i=1;i<=m;i++)
	{
		if(id>n)id-=n;
		else if(i%2==1)
		{
			cout<<i<<" "<<id;
			return 0;
		}
		else
		{
			cout<<i<<" "<<n-id+1;
			return 0;
		}
	}
	return 0;
}
