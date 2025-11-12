#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
struct node{int v;bool r;}a[105];
int ans[15][15],n,m,tot,cur,ans1,ans2;
bool operator <(node a,node b)
{
	return a.v>b.v;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)cin >> a[i].v;
	a[1].r=1;
	sort(a+1,a+n*m+1);
	cur=1;
	while(!a[cur].r)cur++;
	ans1=cur/n;
	cur%=2*n;
	if(cur && cur<=n)
	{
		ans1++;
		ans2=cur;
	}
	else if(cur)
	{
		ans1+=2;
		cur-=n;
		ans2=n-cur+1;
	}
	else
	{
		ans2=n;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
} 
