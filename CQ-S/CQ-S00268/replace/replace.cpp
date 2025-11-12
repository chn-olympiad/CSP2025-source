#include<bits/stdc++.h>
#define ll long long
#define db double
#define int ll//#
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
int n,q,c[200005];
string s1[200005],s2[200005];
//bool b1[5000001],b2[5000001];
vector<int>ci[5000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[++tot];
		cin>>s2[tot];
		if(s1[tot]==s2[tot])
		{
			tot--;
			continue;
		}
		c[tot]=s1[tot].size()-s2[tot].size();
		ci[c[tot]].pb(tot);
	}
	n=tot;
//	cerr<<n<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		cerr<<s1[i]<<" "<<s2[i]<<"\n";
//	}
	int ans=0;
	for(int tt=1;tt<=q;tt++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ct=t1s-t2s,fr=-1,ba=-1,ms=min(t1s,t2s);
		ans=0;
		for(int i=0;i<ms;i++)
		{
			if(t1[i]==t2[i])
			{
				fr++;
			}
			else break;
		}
		for(int i=0;i<ms;i++)
		{
			if(t1[t1s-i]==t2[t2s-i])
			{
				ba++;
			}
			else break;
		}
		for(auto i:ci[ct])
		{
			int ns=t1s-fr-ba-2;
			if(ns>s1[i].size())continue;
			if(t2s-fr-ba-2>s2[i].size())continue;
			if(c[i]!=ct||t2.find(s2[i])>=t2.size())continue;
			int si1=s1[i].size(),si2=s2[i].size();
			int lst=-1;
			while(1)
			{
				lst=t1.find(s1[i],lst+1);
				if(lst>=t1s)break;
				if(lst>fr+1)break;
				if(lst+si1-1<t1s-ba-1-1)continue;
				bool tmp=true;
				for(int j=lst;j<=lst+si2-1;j++)
				{
					if(t2[j]!=s2[i][j-lst])tmp=false;
				}
				if(tmp)
				{
//					cerr<<i<<"*\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

