#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=205;
int a[maxn];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,x=1,y=1;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int now=a[1],cnt=1,p=1;
	sort(a+1,a+1+n*m,greater<int>());
	while(1)
	{
		if(now==a[cnt])
		{
			cout<<y<<' '<<x;
			return 0;
		}
		x+=p;
		if(x>n||x<1) x-=p,p=(p==-1?1:-1),y++;
		cnt++;
	}
	return 0;
}
