#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
const int maxn=2e5+114,maxm=5e6+114; 
string a[maxn],b[maxn],c[maxn],d[maxn];
map<pair<string,string>,ll> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	rep(i,1,n)
	{
		cin>>a[i]>>b[i];
		if(mp.count({a[i],b[i]})) mp[{a[i],b[i]}]++;
		else mp[{a[i],b[i]}]=1;
	}
	rep(Q,1,q)
	{
		string c,d;
		cin>>c>>d;
		if(c.length()!=d.length())
		{
			cout<<0<<endl;
			continue;
		}
		int n=c.length();ll ans=0;
		rep(L,0,n-1)
		{
			rep(R,L,n-1)
			{
				if(L!=0 and c.substr(0,L)!=d.substr(0,L)) continue;
				if(R!=n-1 and c.substr(R+1,n-R-1)!=d.substr(R+1,n-R-1)) continue;
				if(mp.count({c.substr(L,R-L+1),d.substr(L,R-L+1)})) ans+=mp[{c.substr(L,R-L+1),d.substr(L,R-L+1)}];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


