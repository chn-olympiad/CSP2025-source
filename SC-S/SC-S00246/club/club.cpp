#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
#define filename "club"
void work()
{
	int n;
	cin >> n;
	vector<int>a(n + 1), b(n + 1), c(n + 1);
	int cnta = 0, cntb = 0, cntc = 0;
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		if(a[i]==max({a[i],b[i],c[i]}))
		{
			ans+=a[i];
			cnta++;
		}
		else if(b[i]==max({a[i],b[i],c[i]}))
		{
			ans+=b[i];
			cntb++;
		}
		else
		{
			ans+=c[i];
			cntc++;
		}
	}
	int tmp=0;
	vector<int>res;
	if(cnta>n/2)
	{
		tmp=cnta-n/2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==max({a[i],b[i],c[i]}))res.push_back(a[i]-max({b[i],c[i]}));
		}
	}
	if(cntb>n/2)
	{
		tmp=cntb-n/2;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==max({a[i],b[i],c[i]}))res.push_back(b[i]-max({a[i],c[i]}));
		}
	}
	if(cntc>n/2)
	{
		tmp=cntc-n/2;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==max({a[i],b[i],c[i]}))res.push_back(c[i]-max({a[i],b[i]}));
		}
	}
	if(tmp)
	{
		sort(res.begin(),res.end());
		for(int i=0;i<tmp;i++)ans-=res[i];
	}
	cout<<ans<<endl;
}
signed main()
{
#ifndef LOCAL
#ifdef filename
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}