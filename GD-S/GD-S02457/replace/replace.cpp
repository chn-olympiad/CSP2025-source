#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1.5e6,ZD=5e6;
int n,q,cnt,p[M][27],sz[M],qm[N],hm[N];
string s[N][2],t[N][2];
vector<int> v[M];
int getnum(char s)
{
	return (int)s-96;
}
void add(int x,string s)
{
	int dq=0,len=s.size();
	for(int i=0;i<len;i++)
	{
		int hh=getnum(s[i]);
		if(!p[dq][hh]) p[dq][hh]=++cnt;
		dq=p[dq][hh];
		if(i==len-1) v[dq].push_back(x),sz[dq]++;
	}
}
int query(int cd,int wz,int zd,string x,string y)
{
	int dq=0,zs=0;
	for(int i=wz;i<cd;i++)
	{
		int hh=getnum(x[i]);
		if(!p[dq][hh]) break;
		dq=p[dq][hh];
		if(sz[dq]&&i>=zd)
		{
			for(int j=0;j<sz[dq];j++)
			{
				int gg=v[dq][j],f=0;
				for(int k=wz;k<=i;k++)
				{
					if(s[gg][1][k-wz]!=y[k])
					{
						f=1;
						break;
					}
				}
				if(!f) zs++;
			}
		}
	}
	return zs;
}
bool pd(string s)
{
	int len=s.size(),s1=0,s2=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='a') s1++;
		if(s[i]=='b') s2++;
	}
	return (s1==len-1)&&(s2==1);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	system("fc replace4.ans replace.out");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		if(s[i][0]==s[i][1]) continue;
		add(i,s[i][0]);
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>t[i][0]>>t[i][1];
		int len=t[i][0].size();
		int mi=1e9,ma=0;
		for(int j=0;j<len;j++)
		{
			if(t[i][0][j]!=t[i][1][j])
			{
				mi=min(mi,j);
				ma=max(ma,j);
			}
		}
		for(int j=0;j<=mi;j++) ans+=query(len,j,ma,t[i][0],t[i][1]);
		cout<<ans<<"\n";
	}
	return 0;
}
