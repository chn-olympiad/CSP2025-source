#include<bits/stdc++.h>
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n,q;
string a[1000001],b[1000001];
int aa[1000001][2],ba[1000001][2];
int ga[1000001][2];
string cur,tar;
int ca[3],ta[3];
int ned[3];
map<pair<int,int>,vector<pair<int,int> > > m;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]=='b')
			{
				aa[i][0]=j;
				aa[i][1]=a[i].size()-j-1;
			}
		}
		for(int j=0;j<b[i].size();j++)
		{
			if(b[i][j]=='b')
			{
				ba[i][0]=j;
				ba[i][1]=b[i].size()-j-1;
			}
		}
		ga[i][0]=ba[i][0]-aa[i][0];
		ga[i][1]=ba[i][1]-aa[i][1];
		pair<int,int> tmp=make_pair(ga[i][0],ga[i][1]);
		m[tmp].push_back(make_pair(aa[i][0],aa[i][1]));
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>cur>>tar;
		for(int j=0;j<cur.size();j++)
		{
			if(cur[j]=='b')
			{
				ca[0]=j;
				ca[1]=cur.size()-j-1;
			}
		}
		for(int j=0;j<tar.size();j++)
		{
			if(tar[j]=='b')
			{
				ta[0]=j;
				ta[1]=tar.size()-j-1;
			}
		}
		ned[0]=ta[0]-ca[0];
		ned[1]=ta[1]-ca[1];
		pair<int,int> tmp=make_pair(ned[0],ned[1]);
		if(m.count(tmp)!=0)
		{
			for(int j=0;j<m[tmp].size();j++)
			{
				if(m[tmp][j].first>ca[0]||m[tmp][j].second>ca[1])
				{
					continue;
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
