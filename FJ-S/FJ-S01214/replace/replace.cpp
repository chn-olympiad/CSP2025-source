#include<bits/stdc++.h>
#define N 5000010
using namespace std;
char c1[N],c2[N];
int n,q,tot,ans;
int sum[N];
map<pair<char,char>,int>son[N];
map<pair<string,string>,int>mp;
void dfs0(int p,int l,int r,int s,int t)
{
	if(s==l&&r==t)
	{
		sum[p]++;
		return;
	}
	if(s==l)
	{
		if(!son[p][{'3',c1[t]}])
			son[p][{'3',c1[t]}]=++tot;
		dfs0(son[p][{'3',c1[t]}],l,r,s,t+1);
	}
	if(t==r)
	{
		if(!son[p][{c1[s],'3'}])
			son[p][{c1[s],'3'}]=++tot;
		dfs0(son[p][{c1[s],'3'}],l,r,s-1,t);
	}
	if(s!=l&&t!=r)
	{
		if(!son[p][{c1[s],c1[t]}])
			son[p][{c1[s],c1[t]}]=++tot;
		dfs0(son[p][{c1[s],c1[t]}],l,r,s-1,t+1);
	}
}
void dfs1(int p,int l,int r,int s,int t)
{
	ans+=sum[p];
	if(s==l&&r==t)
		return;
	for(auto newp:son[p])
	{
		if(newp.first.first=='3'&&newp.first.second==c1[t])
			dfs1(newp.second,l,r,l,t+1);
		if(newp.first.first==c1[s]&&newp.first.second=='3')
			dfs1(newp.second,l,r,s-1,r);
		if(newp.first.first==c1[s]&&newp.first.second==c1[t])
			dfs1(newp.second,l,r,s-1,t+1);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c1+1>>c2+1;
		int l=1,r=strlen(c1+1),strl=r;
		bool flag=1;
		for(int j=1;j<=r;j++)
			if(c1[j]!=c2[j])
			{
				flag=0;
				break;
			}
		if(!flag)
		{
			while(c1[l]==c2[l])
				l++;
			while(c1[r]==c2[r])
				r--;
			string s1="",s2="";
			for(int j=l;j<=r;j++)
				s1+=c1[j];
			for(int j=l;j<=r;j++)
				s2+=c2[j];
			if(!mp[{s1,s2}]) 
				mp[{s1,s2}]=++tot;
			dfs0(mp[{s1,s2}],0,strl+1,l-1,r+1);
		}
		else
		{
			if(!mp[{"",""}]) 
				mp[{"",""}]=++tot;
			dfs0(mp[{"",""}],0,strl+1,0,1);
		}
	}
	while(q--)
	{
		ans=0;
		cin>>c1+1>>c2+1;
		if(strlen(c1+1)!=strlen(c2+1))
		{
			puts("0");
			continue;
		}
		int l=1,r=strlen(c1+1),strl=r;
		bool flag=1;
		for(int j=1;j<=r;j++)
		if(c1[j]!=c2[j])
		{
			flag=0;
			break;
		}
		if(!flag)
		{
			while(c1[l]==c2[l])
				l++;
			while(c1[r]==c2[r])
				r--;
			string s1="",s2="";
			for(int j=l;j<=r;j++)
				s1+=c1[j];
			for(int j=l;j<=r;j++)
				s2+=c2[j];
			if(!mp[{s1,s2}])
			{
				puts("0");
				continue;
			}
			dfs1(mp[{s1,s2}],0,strl+1,l-1,r+1);
			cout<<ans<<'\n';
		}
		else
		{
			if(!mp[{"",""}])
			{
				puts("0");
				continue;
			}
			dfs1(mp[{"",""}],0,strl+1,0,1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
