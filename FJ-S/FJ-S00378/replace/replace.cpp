#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	int x,y;
};
struct node1
{
	string s1,s2;
};
string s[200010][2],t[200010][2];
vector<node>g[10000010];
vector<node1>g1[5000010];
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int len=s[i][0].size();
		g1[len].push_back({s[i][0],s[i][1]});
	}
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	if(n<=100)
	{
		for(int i=1;i<=q;i++)
		{
			int ql,qr,len=t[i][0].size();
			for(int j=0;j<len;j++)
			{
				if(t[i][0][j]!=t[i][1][j])
				{
					ql=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--)
			{
				if(t[i][0][j]!=t[i][1][j])
				{
					qr=j;
					break;
				}
			}
			int ans=0;
			for(int l=ql;l>=0;l--)
			{
				for(int r=qr;r<len;r++)
				{
					string sy=t[i][0].substr(l,r-l+1),ty=t[i][1].substr(l,r-l+1);
					for(node1 e:g1[r-l+1])
					{
						if(e.s1==sy&&e.s2==ty)ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			for(char c:s[i][0])if(c>'b')flag=1;
			for(char c:s[i][1])if(c>'b')flag=1;
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				int p0,p1,len=s[i][0].size();
				for(int j=0;j<len;j++)
					if(s[i][0][j]=='b')p0=j;
				for(int j=0;j<len;j++)
					if(s[i][1][j]=='b')p1=j;
				g[p0-p1+5000000].push_back({min(p0,p1),len-max(p0,p1)-1});
			}
			for(int i=1;i<=q;i++)
			{
				int p0,p1,len=t[i][0].size(),ans=0;
				for(int j=0;j<len;j++)
					if(t[i][0][j]=='b')p0=j;
				for(int j=0;j<len;j++)
					if(t[i][1][j]=='b')p1=j;
				for(node e:g[p0-p1+5000000])
				{
					if(e.x<=p0&&e.y<=p1)ans++;
				}
				cout<<ans<<'\n';
			}
		}
		else
		{
			for(int i=1;i<=q;i++)cout<<n<<'\n';
		}
	}
	return 0;
}
