#include <bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],t1[200010],t2[200010];
int book1[30],book2[30],len[200010];
bool cmp(int x,int y)
{
	return x>y;
}
struct Pos
{
	int from,to,dis;
}pos[200010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		// for(int j=0;j<26;j++) book1[j]=book2[j]=0;
		// for(int j=0;j<len[i];j++)
		// {
		// 	book1[s1[i][j]-'a']++;
		// 	book2[s2[i][j]-'a']++;
		// }
		// if(book1[0]!=len[i]-1||book1[1]!=1||book2[0]!=len[i]-1||book2[1]!=1) flag=1;

	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<len[i];j++)
		{
			if(s1[i][j]=='b') pos[i].from=j;
		}
		for(int j=0;j<len[i];j++)
		{
			if(s2[i][j]=='b') pos[i].to=j;
		}
		pos[i].dis=pos[i].from-pos[i].to;
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>t1[i]>>t2[i];
		int from,to,dis,len;
		len=t1[i].size();
		for(int j=0;j<len;j++)
		{
			if(t1[i][j]=='b') from=j;
		}
		for(int j=0;j<len;j++)
		{
			if(t2[i][j]=='b') to=j;
		}
		dis=from-to;
		for(int j=1;j<=n;j++)
		{
			if(pos[j].from<from&&pos[j].to<to&&pos[j].dis==dis) ans++;
		}
		cout<<ans<<endl;
	}
}