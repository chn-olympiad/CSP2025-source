#include <bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
const int mod=1e7+13;
const int base=27;
int n,q;
char s1[maxn],s2[maxn];
string sa,sb;
int len[maxn];
int hash1[maxn],hash2[maxn];
inline int hashing(char s[],int len)
{
	int sum=0;
	for(int i=1;i<=len;i=-~i)
	{
		sum*=base;
		sum=sum-(sum/mod)*mod;
		sum+=s[i];
		sum=sum-(sum/mod)*mod;
	}
	sum=sum-(sum/mod)*mod;
	return sum;
}
inline void cmp(string a,string b,int zb)
{
	int cnta=0;
	int cntb=0;
	int fl=0;
	for(register int i=0;i<a.length();i=-~i)
	{
		if(a[i]!=b[i])
		{
			fl=1;
			cnta=-~cnta;
			cntb=-~cntb;
			s1[cnta]=a[i];
			s2[cntb]=b[i];
		}
		else
		{
			if(fl)
			{
				cnta=-~cnta;
				cntb=-~cntb;				
				s1[cnta]=a[i];
				s2[cntb]=b[i];
			}
		}
	}
	for(;cnta>0;)
	{
		if(s1[cnta]!=s2[cntb]) break;
		cnta--;
		cntb--;
	}
	hash1[zb]=hashing(s1,cnta);
	hash2[zb]=hashing(s2,cntb);
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(register int i=1;i<=n;i=-~i)
	{
		cin>>sa>>sb;
		cmp(sa,sb,i);
	}
	
	for(register int i=1;i<=q;i=-~i)
	{
		cin>>sa>>sb;
		cmp(sa,sb,n+i);
		int cnt=0;
		for(register int j=1;j<=n;j=-~j)
		{
			if(hash1[j]==hash1[i+n]&&hash2[j]==hash2[i+n])
			{
				cnt=-~cnt;
			}			
		}
		cout<<cnt<<"\n";
	}
	
	
	return 0;
}

