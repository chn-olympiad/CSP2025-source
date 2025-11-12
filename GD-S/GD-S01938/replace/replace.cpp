#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)
#define db double

const int N=5e6;

int n,q;
map<int,vector<pair<pii,int>>>mp;
struct line
{
	int l,siz,ca;
	bool operator <(line b)
	{
		if(ca!=b.ca)return ca<b.ca;
		return l<b.l;
	}
}a[N+5];
int ans[N+5];
ll tr[N+5];

void add(int x,int y){for(;x<=n;x+=x&-x)tr[x]+=y;}

int query(int x)
{
	int ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}

void solve()
{
	cin>>n>>q;
	string s1,s2;
	for(int i = 1;i<=n;i++)
	{
		cin>>s1>>s2;
		int m=s1.size();
		int l,r;
		for(int j = 0;j<m;j++)
		{
			if(s1[j]=='b')l=j;
			if(s2[j]=='b')r=j;
		}
		a[i].l=l;
		a[i].siz=m;
		a[i].ca=l-r;
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>s1>>s2;
		int m=s1.size();
		int l=n,r=n;
		for(int j = 0;j<m;j++)
		{
			if(s1[j]=='b')l=j;
			if(s2[j]=='b')r=j;
		}
		mp[l-r].push_back({{l,m},i});
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)
	{
		int l=i;
		int r=l;
		while(r+1<=n&&a[r+1].ca==a[l].ca)r++;
		int j=l-1;
		for(auto p:mp[a[l].ca])
		{
			int l=p.first.first;
			int siz=p.first.second;
			int id=p.second;
			while(j+1<=r&&a[j+1].l<=l){j++;add(a[j].siz-a[j].l,1);}
			ans[id]=query(siz-l);
		}
		for(int k = l;k<=j;k++)add(a[k].siz-a[k].l,-1);
		i=r;
	}
	for(int i = 1;i<=q;i++)cout<<ans[i]<<endl;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

