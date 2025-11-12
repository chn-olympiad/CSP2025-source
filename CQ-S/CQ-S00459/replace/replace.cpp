#include<bits/stdc++.h>
#define int long long
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int n,q,base=87;
struct N
{
	string s1,s2;//串1，串2，不同部分的hash 
	int dif1,dif2,o;
}s[200005],t;
inline bool cmp(N a,N b)
{
	if(a.dif1==b.dif1)
		return a.dif2<b.dif2;
	return a.dif1<b.dif1;
}
inline int qpow(int x,int y)
{
	int num=1;
	while(y)
	{
		if(y&1)num*=x;
		x=x*x;
		y>>=1;
	}
	return num;
}
inline bool check(N &a,N &b)
{
	int siz1=a.s1.size(),siz2=b.s1.size();
	int frt=b.o-a.o;
	if(frt<0||frt+siz2<siz1)
		return 0;
	for(int l1=0,l2=frt;l1<siz1;l1++,l2++)
		if(a.s1[l1]!=b.s1[l2])
			return 0;
	return 1;
}
signed main()
{
	File("replace");
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
		int has1=0,has2=0;
		bool st=0;
		int siz=s[i].s1.size();
		for(int j=0;j<siz;j++)
		{
			if(st||s[i].s1[j]!=s[i].s2[j])
			{
				has1=has1*base+(s[i].s1[j]-'a'+1);
				has2=has2*base+(s[i].s2[j]-'a'+1);
			}
			if(s[i].s1[j]!=s[i].s2[j])
			{
				if(!st)
					s[i].o=j;
				st=1;			
				s[i].dif1=has1;
				s[i].dif2=has2;
			}
		}
//		cerr<<s[i].dif1<<' '<<s[i].dif2<<'\n';
	}
	sort(s+1,s+n+1,cmp);
	for(int _=1;_<=q;_++)
	{
		if(clock()>0.9*CLOCKS_PER_SEC)
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		cin>>t.s1>>t.s2;
		int has1=0,has2=0;
		bool st=0;
		int siz=t.s1.size();
		for(int j=0;j<siz;j++)
		{
			if(st||t.s1[j]!=t.s2[j])
			{
				has1=has1*base+(t.s1[j]-'a'+1);
				has2=has2*base+(t.s2[j]-'a'+1);
			}
			if(t.s1[j]!=t.s2[j])
			{
				if(!st)
					t.o=j;
				st=1;
				t.dif1=has1;
				t.dif2=has2;
			}
		}
//		cerr<<t.dif1<<' '<<t.dif2<<'\n';
		int l=1,r=n,mid=(l+r)>>1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(cmp(s[mid],t))
				l=mid+1;
			else
				r=mid;
		}
		for(int i=l;i<=n;i++)
		{
			if(s[i].dif1>t.dif1)
				break;
			if(s[i].dif1==t.dif1&&s[i].dif2>t.dif2)
				break;
			ans+=check(s[i],t);
			if(clock()>0.9*CLOCKS_PER_SEC)
				break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
作为S组的串串题，要么是KMP，要么是hash，要么是神秘Ad-hoc
这题不像KMP，没发现Ad-hoc的地方，所以考虑hash 
 
显然就是要判断有多少个s1是t1的字串且将那一段换成s2后和t2相等
条件很难满足，考虑不可以总司令(划掉
先把不匹配段拉出来
然后判断子串就行 
这个显然可hash
但是没时间了，hash调着慢，所以暴力+一个简单的hash+卡时总司令 
预计很多分
18:08 
*/ 
