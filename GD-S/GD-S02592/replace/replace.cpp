#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,p[5141919]={1},ans;
int const P=131;
string s1[314159],s2[314159],t1,t2;
vector<int> v1,v2,h1,h2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=5000000;i++)
	{
		p[i]=p[i-1]*P;
	}
	cin>>n>>m;
	v1.resize(n+1);
	v2.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j=1;j<=s1[i].size();j++)
		{
			v1[i]=v1[i]*P+s1[i][j-1];
			v2[i]=v2[i]*P+s2[i][j-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		cin>>t1>>t2;
		h1.clear();
		h2.clear();
		h1.resize(t1.size()+1);
		h2.resize(t2.size()+1);
		for(int j=1;j<=t1.size();j++)
		{
			h1[j]=h1[j-1]*P+t1[j-1];
			h2[j]=h2[j-1]*P+t2[j-1];
		}
		for(int j=1;j<=n;j++)
		{
			if(t1.size()<s1[j].size())
			{
				continue;
			}
			for(int k=1;k<=t1.size()-s1[j].size()+1;k++)
			{
				
				int l=k+s1[j].size()-1;
				if(h1[l]-h1[k-1]*p[l-k+1]==v1[j])
				{
					if(h1[t1.size()]-v1[j]*p[t1.size()-l]+v2[j]*p[t2.size()-l]==h2[t2.size()])
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
