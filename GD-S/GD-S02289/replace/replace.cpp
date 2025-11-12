#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t1[N][26],t2[N][26],f1[N],f2[N];
int n,q,cnt1,cnt2;
void build(string s1,string s2)
{
	int rt=0;
	for(int i=0;i<(int)s1.size();i++)
	{
		int cnt=s1[i]-'a';
		if(!t1[rt][cnt]) t1[rt][cnt]=++cnt1;
		rt=t1[rt][cnt];
	}
	f1[rt]=1;
	rt=0;
	for(int i=0;i<(int)s2.size();i++)
	{
		int cnt=s2[i]-'a';
		if(!t2[rt][cnt]) t2[rt][cnt]=++cnt2;
		rt=t2[rt][cnt];
	}
	f2[rt]=1;
	return;
}
pair<int,int> dfs(int pos,string s1,string s2)
{
	int ans=0,len=0,rt1=0,rt2=0;
	int p1=s1[pos]-'a',p2=s2[pos]-'a';
	while(t1[rt1][p1]&&t2[rt1][p2])
	{
		rt1=t1[rt1][p1],rt2=t2[rt2][p2];
		if(f1[rt1]||f2[rt2]) ans++;
		len++; 
		pos++;
		p1=s1[pos]-'a',p2=s2[pos]-'a';
	}
	//if(f1[rt1]||f2[rt2]) ans++;
	return {ans,len};
} 
int check(string s1,string s2)
{
	int res=0;
	for(int i=0;i<(int)s1.size();i++)
	{
		auto x=dfs(i,s1,s2);
		int ans=x.first,len=x.second;
		bool fl=1;
		//cout<<ans<<"!!!!!\n"; 
		for(int j=i+len+1;j<(int)s1.size();j++)
		{
			if(s1[j]!=s2[j])
			{
				fl=0;
				break;
			}
		}
		if(fl) res+=ans;
		if(s1[i]!=s2[i])break;
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		build(s1,s2);
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		cout<<check(s1,s2)<<'\n';
	}
	return 0;
}
