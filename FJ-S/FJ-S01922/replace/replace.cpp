#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define per(a,b,c) for(int a=(c);a>=(b);a--)
#define fc freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
#define debug(x) cout<<x<<'\n';
using ull=unsigned long long;
const int N=5e6+10;
const ull BASE=131;
ull hs1[N],hs2[N],pw[N];
ull gh1(int l,int r)
{
	if(l>r) return 0;
	return hs1[r]-hs1[l-1]*pw[r-l+1];
}
ull gh2(int l,int r)
{
	if(l>r) return 0;
	return hs2[r]-hs2[l-1]*pw[r-l+1];
}
bool check(int l,int r)
{
	return gh1(l,r)==gh2(l,r);
}
void solve()
{
	int n,q;
	cin>>n>>q;
	map<string,map<string,int>> mp;//¶ÔÓ¦Ìæ»» 
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a][b]=1;
	}
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*BASE;
	while(q--){	
	string t1,t2;
	cin>>t1>>t2;
	int len=t1.size();
	t1=' '+t1,t2=' '+t2;	
	for(int i=1;i<=len;i++)
	{
		hs1[i]=hs1[i-1]*BASE+t1[i];
		hs2[i]=hs2[i-1]*BASE+t2[i];
	}
	int ans=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=i;j<=len;j++)
		{
			if(!check(1,i-1)||!check(j+1,len)) continue; 
			string sa="",sb="";
			for(int k=i;k<=j;k++) sa+=t1[k],sb+=t2[k];
			if(mp[sa][sb]>=1) ++ans;
		}
	}
	cout<<ans<<'\n';
	}
}
signed main()
{
	fc;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
