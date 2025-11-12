/*
17:26开C，目前估分是100+[48,100]T2的下届几乎不可能达到，只要数据是用随机出的
只要不是瞪着的我做法出数据，我就有至少80分
首先做AB
显然去吧s扫一遍就好了
单有A的话就是把si1和ti1那个唯一的b对齐了（此时若ti1=ti2就是si1=si2且s是t子串的数量） 
先写个最暴力的东西吧 
拼尽全力拿了5分哈哈哈
100+[48,100]+5 
*/
#include<bits/stdc++.h>
using namespace std;
string s1[300],s2[300];
vector<int>build(string &p)
{
	int m=p.size();
	vector<int>nxt(m,0);
	for(int i=1,j=0;i<m;i++)
	{
		while(j>0&&p[i]!=p[j])
		{
			j=nxt[j-1];
		}
		if(p[i]==p[j])
		{
			j++;
		}
		nxt[i]=j;
	}
	return nxt;
}
vector<int> kmp(string &s,string &p)
{
	int n=s.size(),m=p.size();
	vector<int>nxt=build(p),res;
	for(int i=0,j=0;i<n;i++)
	{
		while(j>0&&s[i]!=p[j])j=nxt[j-1];
		if(s[i]==p[j])j++;
		if(j==m)
		{
			res.push_back(i-m+1);
			j=nxt[j-1];
		}
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int cret=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s1[i])
		{
			cret++;
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ret=0;
		if(t1==t2)
		{
			for(int i=1;i<=n;i++)
			{
				vector<int>rs=kmp(t1,s1[i]);
				if(rs.size()&&s1[i]==s2[i])
				{
					ret+=rs.size();
				}
			}
		}
		else
		{
			int nn=t1.size();
			int cnt1,cnt2;
			for(int i=0;i<nn;i++)
			{
				if(t1[i]=='b')
				{
					cnt1=i;
				}
			}
			for(int i=0;i<nn;i++)
			{
				if(t2[i]=='b')
				{
					cnt2=i;
				}
			}
			for(int j=1;j<=n;j++)
			{
				int an=s1[j].size();
				for(int k=0;k<an;k++)
				{
					//cout<<k-cnt2+cnt1<<"\n";
					if(cnt1<cnt2)
						if(s1[j][k]=='b'&&s2[j][k+cnt2-cnt1]=='b')ret++;
					if(cnt1<cnt2&&k-(cnt2-cnt1)>=0)
						if(s1[j][k]=='b'&&s2[j][k-(cnt2-cnt1)]=='b')ret++;
					if(cnt1>cnt2&&k-(cnt1-cnt2)>=0)
					{
						if(s1[j][k]=='b'&&s2[j][k-(cnt1-cnt2)]=='b')ret++;
					}
					if(cnt1>cnt2)
					{
						if(s1[j][k]=='b'&&s2[j][k+(cnt1-cnt2)]=='b')ret++;
					}
				}
			}
			if(cret!=0)
			{
				for(int i=1;i<=n;i++)
				{
					vector<int>rs=kmp(t1,s1[i]);
					if(rs.size()&&s1[i]==s2[i])
					{
						ret+=rs.size();
					}
				}
			}
		}
		cout<<ret;
	}
}
