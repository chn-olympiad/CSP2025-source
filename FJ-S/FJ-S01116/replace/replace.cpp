#include<bits/stdc++.h>
using namespace std;
int n,t;
string s1,s2,t1,t2;
int ans=0;
map<string,int>mp;
vector<pair<string,string>>f[100];
vector<char>s;
int query(int st,string x1,string x2)
{
	for(char ch:x1)s.push_back(ch);
	for(int i=1;i<st;i++)s.erase(s.begin());
	string now="";
	int d=0;int len=x1.length();
	for(int i=0;i<len;i++) d+=(x1[i]!=x2[i]);
	if(x1==x2)return 1;
	if(st==len)return (x1==x2);
	for(int i=st;i<len;i++)
	{
	  bool res=1;
	  for(auto p:f[x1[i]-'a'])
	    {
	      vector<char>b=s;
	      if(!mp[p.first]) continue;
	      bool res1=0;
	      int o=p.first.length();
	      for(int k=0;k<o;k++)
	        if(p.first[k]!=x1[k+i] || p.second[k]!=x2[k+i])
	        {res1=1;break;}
	        else b.erase(b.begin());
	      if(res1)continue;
	      string add="";
	      for(char ch:b) add+=ch;
	      res&=res1;
	      mp[p.first]--,ans+=query(i+o+1,now+p.second+add,x2),mp[p.first]++;
		}
	now+=x1[i];
		s.erase(s.begin());
	  res&=(x1[i]!=x2[i]);
	  if(res) return 0;
	}
	return 1;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	  cin>>s1>>s2,
	  f[s1[0]-'a'].push_back(make_pair(s1,s2)),
	  mp[s1]++;
	while(t--)
	  ans=0,cin>>t1>>t2,query(0,t1,t2),cout<<ans<<'\n';
	return 0;
}