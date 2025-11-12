#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;

int t, n, x, y, z, ans;
struct wor
{
	int p, q, r;
} a[N];
bool cmp(wor a, wor b)
{
	return max(a.p, max(a.q, a.r))>max(b.p, max(b.q, b.r));
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--)
	{
		ans=0, x=0, y=0, z=0;
		cin>>n;
		int m=n/2;
		for(int i=1; i<=n; i++) cin>>a[i].p>>a[i].q>>a[i].r;
		sort(a+1, a+n+1, cmp);
		for(int i=1; i<=n; i++)
		{
			if(x!=m&&y!=m&&z!=m)
			{
				if(a[i].p>a[i].q&&a[i].p>a[i].r) x++, ans+=a[i].p;
				if(a[i].q>a[i].p&&a[i].q>a[i].r) y++, ans+=a[i].q;
				if(a[i].r>a[i].q&&a[i].r>a[i].p) z++, ans+=a[i].r;
			}
			else if(x>=m)
			{
				if(a[i].r>=a[i].q) z++, ans+=a[i].r;
				else y++, ans+=a[i].q;
			}
			else if(y>=m)
			{
				if(a[i].r>=a[i].p) z++, ans+=a[i].r;
				else x++, ans+=a[i].p;
			}
			else if(z>=m)
			{
				if(a[i].p>=a[i].q) x++, ans+=a[i].p;
				else y++, ans+=a[i].q;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

