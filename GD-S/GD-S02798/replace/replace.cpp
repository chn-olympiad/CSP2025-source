#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q,ans;
string s1[N],s2[N];
int c1[N],c2[N];
int st1[N*30],st2[N*30];
bool cmp(pair<int,int>a,pair<int,int>b)
{return a.first==b.first?a.second<b.second:a.first<b.first;}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
//	if(n<=100&&q<=100)
//	{
		map<pair<string,string>,int>mp;
		for(int i=1;i<=n;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			mp[{s1,s2}]++;
		}
		while(q--)
		{
			string s1,s2;
			cin>>s1>>s2;ans=0;
			if(s1.size()!=s2.size())
			{cout<<"0\n";continue;}
			int m=s1.size(),l=0,r=0;
			s1=" "+s1,s2=" "+s2;
			for(int i=1;i<=m;i++)
				if(s1[i]!=s2[i])
					r=i;
			for(int i=m;i>=1;i--)
				if(s1[i]!=s2[i])
					l=i;
			string t1="",t2="";
			for(int i=l;i<r;i++)
				t1+=s1[i],t2+=s2[i];
			for(int i=l;i>=1;i--)
			{
				if(i!=l)
				t1=s1[i]+t1,t2=s2[i]+t2;
				string tp1=t1,tp2=t2;
				for(int j=r;j<=m;j++)
				{
					tp1=tp1+s1[j],tp2=tp2+s2[j];
					if(mp.count({tp1,tp2}))
						ans+=mp[{tp1,tp2}];
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
//	}
//	bool spA=1;int sumb=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>s1[i]>>s2[i];
//		for(int j=0;j<s1[i].size();j++)
//			c1[i]+=s1[i][j]*c1[i]*10003,c1[i]%=998244353;
//		for(int j=0;j<s2[i].size();j++)
//			c2[i]+=s2[i][j]*c2[i]*10003,c2[i]%=998244353;
//		int sumb=0;
//		for(int j=0;j<s1[i].size();j++)
//		{
//			if(s1[i][j]>'b')spA=0;
//			if(s1[i][j]=='b')sumb++;
//		}
//		if(sumb>1)spA=0;
//		for(int j=0;j<s2[i].size();j++)
//		{
//			if(s2[i][j]>'b')spA=0;
//			if(s2[i][j]=='b')sumb++;
//		}
//		if(sumb>1)spA=0;
//	}
//	if(spA)
//	{
//		vector<pair<int,int>>a[2][N*30];
//		for(int i=1;i<=n;i++)
//		{
//			int p1,p2;
//			for(int j=0;j<s1[i].size();j++)
//				if(s1[i][j]=='b'){p1=j;break;}
//			for(int j=0;j<s2[i].size();j++)
//				if(s2[i][j]=='b'){p2=j;break;}
//			if(p1<p2)a[0][p2-p1].push_back({p1,s2[i].size()-p2-1});
//			else a[1][p1-p2].push_back({p2,s1[i].size()-p1-1});
//		}
//		for(int i=0;i<N*30;i++)
//		for(int j=0;j<=1;j++)
//			if(a[j][i].size())
//				sort(a[j][i].begin(),a[j][i].end(),cmp);
//		while(q--)
//		{
//			string t1,t2;
//			cin>>t1>>t2;
//			if(t1.size()!=t2.size())
//			{cout<<"0"<<endl;continue;}
//			int m=t1.size();
//			t1=" "+t1;
//			t2=" "+t2;
//			int p1,p2;
//			for(int i=1;i<=m;i++)
//				if(t1[i]=='b'){p1=i;break;}
//			for(int i=1;i<=m;i++)
//				if(t2[i]=='b'){p2=i;break;}
//			if(p1<p2)
//		}
//	}
//	while(q--)
//	{
//		string t1,t2;
//		cin>>t1>>t2;
//		if(t1.size()!=t2.size())
//		{cout<<"0"<<endl;continue;}
//		int m=t1.size();
//		t1=" "+t1;t2=" "+t2;
//			
//	}
	return 0;
}
