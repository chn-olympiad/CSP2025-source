#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
//#define int long long
using namespace std;
unsigned long long p=415411;
const int N=1e6+10;
int n,q;
unsigned long long fac[N];
unsigned long long h[N][2],h1[N],h2[N];
string s[N][2],t1,t2;
struct node{int m,x,y;}a[N];
set<pair<unsigned long long,unsigned long long>,int> s;
int main()
{
	fre("replace");
	s.clear();
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*p;
	cin>>n>>q;
	for(int i=1;i<=n;i++)for(int j=0;j<2;j++)cin>>s[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			h[i][j]=0;
			for(int k=0;k<s[i][j].size();k++)h[i][j]=h[i][j]*p+s[i][j][k]);
		}
		s[make_pair(h[i][0],h[i][1])]++;
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=1;i<=t1.size();i++)
		{
			h1[i]=h1[i-1]*p+t1[i-1];
			h2[i]=h2[i-1]*p+t2[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(h1[i]==h2[i]&&h1[j]==j2[j])continue;
				unsigned long long x=(h2[i]-h1[i]);
			}
		}
	}
}
