#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5,N=5e6+5;
int n,m;
string s[M][2],t[M][2];
vector<int> p[M][2];
void get_p(int x)
{
	p[x][0].push_back(0);
	p[x][0].push_back(1);
	p[x][1].push_back(0);
	p[x][1].push_back(1);
	int j1=0,j2=0;
	for(int i=2;i<s[i][0].size();i++)
	{
		while(j1&&s[x][0][p[x][0][j1]]!=s[x][0][j1+1])
			j1=p[x][0][j1];
		if(s[x][0][p[x][0][j1]]==s[x][0][j1+1])
			j1++;
		p[x][0].push_back(j1);
		while(j2&&s[x][1][p[x][1][j2]]!=s[x][1][j2+1])
			j2=p[x][1][j2];
		if(s[x][1][p[x][1][j2]]==s[x][1][j2+1])
			j2++;
		p[x][1].push_back(j2);
//		cout<<p[x][0][i]<<' '<<p[x][1][i]<<'\n';
	}
}
int kmp(int x,int y,int l,int r)
{
	int j1=1,j2=1,sum=0;
	for(int i=1;i<t[i][0].size();i++)
	{
		while(j1&&t[x][0][i]!=s[y][0][j1+1])
			j1=p[x][0][j1];
		if(t[x][0][i]==s[y][0][j1+1])
			j1++;
		while(j2&&t[x][1][i]!=s[y][1][j2+1])
			j2=p[x][1][j2];
		if(t[x][1][i]==s[y][1][j2+1])
			j2++;
		if(j1==s[x][0].size()-1&&j2==s[x][0].size()-1)
		{
			if(i>=r&&i-s[x][0].size()+2<=l)
				sum++;
		}
		if(j1==s[x][0].size()-1)
			j1=p[x][0][j1];
		if(j2==s[x][0].size()-1)
			j2=p[x][1][j2];
	}
	return sum;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
		get_p(i);
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size())
		{
			cout<<0<<'\n';
			continue;			
		}
		t[i][0]=" "+t[i][0];
		t[i][1]=" "+t[i][1];
		int x,y;
		for(int j=1;j<t[i][0].size();j++)
		{
			if(t[i][0][j]!=t[i][1][j])
			{
				x=j;
				break;
			}
		}
		for(int j=t[i][0].size()-1;j>=1;j--)
		{
			if(t[i][0][j]!=t[i][1][j])
			{
				y=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(s[j][0].size()-1<y-x+1)
				continue;
			ans+=kmp(i,j,x,y);
		}
		cout<<ans<<'\n';
	}
	
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
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

Ren5Jie4Di4Ling5%
*/
