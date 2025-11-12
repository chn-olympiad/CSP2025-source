#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct str
{
	ll a1,a2,a3,pl;
	str(ll u,ll v,ll w,ll k)
	{
		a1=u,a2=v,a3=w,pl=k;
	}
};
void dfs(ll n,ll k,ll cnt,vector<str> &ve,ll &ans,ll c1,ll c2,ll c3)
{
	if(!((c1<=(n/2))&&(c2<=(n/2))&&(c3<=(n/2))))
	{
		return ;
	}
	if(k>=n)
	{
		if((c1<=(n/2))&&(c2<=(n/2))&&(c3<=(n/2)))
		{
			ans=cnt>ans?cnt:ans;
		}
		return ;
	}
//	cout<<k<<"-1\n";
	dfs(n,k+1,cnt+ve[k].a1,ve,ans,c1+1,c2,c3);
//	cout<<k<<"-2\n";
	dfs(n,k+1,cnt+ve[k].a2,ve,ans,c1,c2+1,c3);
//	cout<<k<<"-3\n";
	dfs(n,k+1,cnt+ve[k].a3,ve,ans,c1,c2,c3+1);
	return ;
}
vector<str> ve;
ll t,n,ans=0;
bool spB=1,spA=1;
bool cmpspB(str a,str b)
{
	return (a.a2-a.a1)<(b.a2-b.a1);
}
bool cmpspA(str a,str b)
{
	return a.a1>b.a1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ve.clear(),ans=0,spB=1,spA=1;
		for(ll i=0,a1,a2,a3;i<n;i++)
		{
			cin>>a1>>a2>>a3;
			ve.push_back({a1,a2,a3,i});
			if(a3!=0)
			{
				spB=0;
			}
			if(a2!=0||a3!=0)
			{
				spA=0;
			}
		}
		if(spA)
		{
			stable_sort(ve.begin(),ve.end(),cmpspA);
			for(ll i=0;i<(n/2);i++)
			{
				ans+=ve[i].a1;
			}
			cout<<ans<<'\n';
		}
		else if(spB)
		{
			for(str v:ve)
			{
				ans+=v.a1;
			}
			stable_sort(ve.begin(),ve.end(),cmpspB);
			ll c1=n;
			while((c1>(n/2))&&(!ve.empty()))
			{
				ans+=(ve.back().a2-ve.back().a1),c1-=1;
				ve.pop_back();
			}
			cout<<ans<<'\n';
		}
		else
		{
			dfs(n,0,0,ve,ans,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}