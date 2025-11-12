#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=120;
int n,m,a[maxn],t;
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1);
	int pos=lower_bound(a+1,a+n*m+1,t)-a;
	pos=n*m+1-pos;
	int c=(pos+n-1)/n,r;
	if(c%2)r=(pos-1)%n+1;
	else r=n-((pos-1)%n);
	cout<<c<<' '<<r;
	return 0;
}