#include <bits/stdc++.h>
using namespace std;
multiset<int,greater<int>> st1,st2,st3;
void solve()
{
	st1.clear();st2.clear();st3.clear();
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ans+=max({a,b,c});
		if(a==max({a,b,c}))	st1.insert(max(b,c)-a);
		else if(b==max({a,b,c})) st2.insert(max(a,c)-b);
		else st3.insert(max(a,b)-c);
	}
	while(st1.size()>n/2)
	{
		ans+=(*st1.begin());
		st1.erase(st1.begin());
	}
	while(st2.size()>n/2)
	{
		ans+=(*st2.begin());
		st2.erase(st2.begin());
	}
	while(st3.size()>n/2)
	{
		ans+=(*st3.begin());
		st3.erase(st3.begin());
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
