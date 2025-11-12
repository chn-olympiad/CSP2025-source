#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=0x3f3f3f3f;
int n;
struct node {int v[3],p,val;}a[N];
void solve()
{
	cin>>n; int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
		int mx=max({a[i].v[0],a[i].v[1],a[i].v[2]});
		ans+=mx;
		if(a[i].v[0]==mx) a[i].p=0;
		else if(a[i].v[1]==mx) a[i].p=1;
		else a[i].p=2;
	}
	int tot[3]{};
	for(int i=1;i<=n;i++) tot[a[i].p]++;
	vector<int>v;
	for(int i=1;i<=n;i++) if(tot[a[i].p]>n/2) v.push_back(i);
	if(v.empty()) {cout<<ans<<"\n"; return;}
	for(auto x:v)
	{
		a[x].val=-INF;
		for(int i=0;i<3;i++) if(i!=a[x].p) a[x].val=max(a[x].val,a[x].v[i]-a[x].v[a[x].p]);
	}
	sort(v.begin(),v.end(),[&](int x,int y) {return a[x].val>a[y].val;});
	for(int i=0;i<(int)v.size()-n/2;i++) ans+=a[v[i]].val;
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t; cin>>t; while(t--) solve();
	return 0;
}