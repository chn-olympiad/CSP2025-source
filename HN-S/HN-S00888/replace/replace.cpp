#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int base=13331;
int n,q;
struct node
{
	string s1,s2;
	int h1,h2;
}ch[200005];
vector<vector<int> > len;
map<int,vector<int> > vis;
int flag[5000005],po[5000005];
int sum[5000005];
int Hash(string s)
{
	int sum=0;
	for(int i=0;i<s.size();i++) sum=sum*base+s[i];
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	po[0]=1;
	for(int i=1;i<=5000000;i++) po[i]=po[i-1]*base;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i].s1>>ch[i].s2;
		ch[i].h1=Hash(ch[i].s1),ch[i].h2=Hash(ch[i].s2);
	}
	len.push_back({0});
	for(int i=1;i<=n;i++)
	{
		if(!flag[ch[i].s1.size()]) len.push_back({i}),flag[ch[i].s1.size()]=len.size()-1;
		else len[flag[ch[i].s1.size()]].push_back(i);
	}
	for(int k=1;k<=q;k++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int t=Hash(s2),len1=s1.size();
		s1=" "+s1;
		for(int i=1;i<=len1;i++) sum[i]=sum[i-1]*base+s1[i];
		for(int i=1;i<len.size();i++)
		{
			int leng=ch[len[i][0]].s1.size();
			for(int j=leng;j<=len1;j++)
			{
				vis[sum[j]-sum[j-leng]*po[leng-1]].push_back(j-leng+1);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int pos=ch[i].h1;
			for(int j=0;j<vis[pos].size();j++)
			{
				if(sum[len1]+(ch[i].h2-ch[i].h1)*po[vis[pos][j]-1]==t)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		vis.clear();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
