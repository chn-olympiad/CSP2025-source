#include<bits/stdc++.h>
#define ll long long
#define emb emplace_back
#define endl '\n'
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q,k1[N],k2[N];
bool flag;
vector<int>b[L],c[L];
string s1[N],s2[N],t1,t2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int p1=0,p2=0;
		for(int j=0;j<s1[i].length();j++)
		{
			if(s1[i][j]!='a'&&s1[i][j]!='b')
			{
				flag=1;
			}
			if(s1[i][j]=='b')
			{
				p1=k1[i]=j;
				break;
			}
		}
		for(int j=0;j<s2[i].length();j++)
		{
			if(s2[i][j]!='a'&&s2[i][j]!='b')
			{
				flag=1;
			}
			if(s2[i][j]=='b')
			{
				p2=k2[i]=j;
				break;
			}
		}
		if(p1>=p2)
		{
			b[p1-p2].emb(i);
		}
		else
		{
			c[p2-p1].emb(i);
		}
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		if(flag)
		{
			int st=-1,ed=0;
			for(int i=0;i<t1.length();i++)
			{
				if(t1[i]!=t2[i])
				{
					if(st==-1)
					{
						st=i;
					}
					ed=i;
				}
			}
			for(int i=1;i<=n;i++)
			{
				int p=0;
				for(int j=0;j<t1.length();j++)
				{
					int k=j;
					while(t1[k]==s1[i][p]&&t2[k]==s2[i][p]&&k<t1.length()&&p<s1[i].length())
					{
						p++;
						k++;
					}
					if(p==s1[i].length()&&k>ed&&j<=st)
					{
						ans++;
						break;
					}
					else
					{
						p=0;
					}
				}
			}
		}
		else
		{
			int p1=0,p2=0;
			for(int i=0;i<t1.length();i++)
			{
				if(t1[i]=='b')
				{
					p1=i;
					break;
				}
			}
			for(int i=0;i<t2.length();i++)
			{
				if(t2[i]=='b')
				{
					p2=i;
					break;
				}
			}
			int x=p1-p2;
			if(x>=0)
			{
				for(int i=0;i<b[x].size();i++)
				{
					int y=b[x][i];
					if(k1[y]<=p1&&s1[y].length()-k1[y]<=t1.length()-p1)
					{
						ans++;
					}
				}
			}
			else
			{
				x=-x;
				for(int i=0;i<c[x].size();i++)
				{
					int y=c[x][i];
					if(k1[y]<=p1&&s1[y].length()-k1[y]<=t1.length()-p1)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
