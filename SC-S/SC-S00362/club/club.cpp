#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+50;
ll n;
ll t;
struct q{
	int a,b,c;
}a[N];
bool cmp_a(q a,q b)
{
	return a.a > b.a;
}
bool cmp_b(q a,q b)
{
	if(a.a == b.a) return a.b > b.b;
	return a.a > b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios:: sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool ok2 = true;
		bool ok3 = true;
		for(int i =1; i <= n ; i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(a[i].b!=0) ok2 = false;
			if(a[i].c!=0) ok3 = false;
		}
		if(ok2&&ok3)
		{
			sort(a+1,a+n+1,cmp_a);
			ll ans = 0;
			for(int i = 1; i <= n/2 ; i ++)
			{
				ans+=a[i].a;
			}
			cout<<ans;
		}
		else if(ok3)
		{
			sort(a+1,a+n+1,cmp_b);
			int cnt_1 = 0,cnt_2 = 0;
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i].a > a[i].b )
				{
					if(cnt_1 < n/2)
					{
						ans += a[i].a;
						cout << a[i].a<<"\n";
						cnt_1++;
					}
					else
					{
						ans+=a[i].b;
					}
						
				}
				if(a[i].a < a[i].b)
				{
					if(cnt_2 < n/2)
					{
						ans += a[i].b;
						cout<<a[i].b<<"\n";
						cnt_2++;
					}
					else
					{
						ans += a[i].a;
					}
				}
				
			}
			cout<<ans;
		}
	}
	return 0;
}
 