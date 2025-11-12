#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,idx;
vector<pair<string,string>>v[2000001];
map<string,int>mp,m1,m2;
map<tuple<string,string,string>,int>tmp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		int i1=-1,i2=-1;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]!=t[j])
			{
				i1=j;
				break;
			}
		}
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s[j]!=t[j])
			{
				i2=j;
				break;
			}
		}
		if(i1==-1||i2==-1) continue;
		string s1="";
		for(int j=0;j<i1;j++) s1+=s[j];
		string s2="";
		for(int j=i2+1;j<s.size();j++) s2+=s[j];
		string s3="";
		for(int j=i1;j<=i2;j++) s3+=s[j];
		s3+='-';
		for(int j=i1;j<=i2;j++) s3+=t[j];
		if(!mp[s3]) mp[s3]=++idx;
		reverse(s1.begin(),s1.end());
		if(!tmp[{s1,s2,s3}]) v[mp[s3]].push_back({s1,s2});
		tmp[{s1,s2,s3}]++;
	}
	for(int i=1;i<=m;i++)
	{
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<0<<"\n";
			continue;
		}
		int i1=-1,i2=-1;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]!=t[j])
			{
				i1=j;
				break;
			}
		}
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s[j]!=t[j])
			{
				i2=j;
				break;
			}
		}
		string s1="";
		for(int j=0;j<i1;j++) s1+=s[j];
		string s2="";
		for(int j=i2+1;j<s.size();j++) s2+=s[j];
		string s3="";
		for(int j=i1;j<=i2;j++) s3+=s[j];
		s3+='-';
		for(int j=i1;j<=i2;j++) s3+=t[j];
		if(!mp[s3])
		{
			cout<<0<<"\n";
			continue;
		}
		m1.clear(),m2.clear();
		string ss="";
		m1[""]=m2[""]=1;
		for(int j=s1.size()-1;j>=0;j--)
		{
			ss+=s1[j];
			m1[ss]=1;
		}
		ss="";
		for(int j=0;j<s2.size();j++)
		{
			ss+=s2[j];
			m2[ss]=1;
		}
		int ans=0;
		for(pair<string,string>x:v[mp[s3]])
		{
			ans+=(m1[x.first]&&m2[x.second])*tmp[{x.first,x.second,s3}];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//If you hear the train I am on, you will know that I am gone.
