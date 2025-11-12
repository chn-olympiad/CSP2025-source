#include<bits/stdc++.h>
using namespace std;
const int range=2e5+5;
const int base=233;
const long long mod1=1e9+9;
int n,q;
struct hush
{
	long long hu1;
	inline void raw(){hu1=0ll;}
	inline void add(char c){((hu1*=base)+=(c-'a'+1))%=mod1;}
	bool operator == (const hush &o) const{return hu1==o.hu1;}
	bool operator > (const hush &o) const{return hu1>o.hu1;}
};
struct unit
{
	int lef,pre;
	hush hdi,hdl,hdr;
}tem,s[range],sl[range],sr[range];
bool cmpi(unit a,unit b){return a.hdi.hu1<b.hdi.hu1;}
bool cmpl(unit a,unit b){return a.hdl.hu1<b.hdl.hu1;}
bool cmpr(unit a,unit b){return a.hdr.hu1<b.hdr.hu1;}
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int len;
		cin >> s1 >> s2;
		len=s1.size();
		int l=len,r=-1;
		for(int j=0;j<len;j++) if(s1[j]!=s2[j]) l=min(l,j),r=max(r,j);
		s[i].hdi.raw();
		for(int j=l;j<=r;j++) s[i].hdi.add(s1[j]);
		for(int j=l;j<=r;j++) s[i].hdi.add(s2[j]);
		s[i].hdl.raw();for(int j=l-1;~j;j--) s[i].hdl.add(s1[j]);
		s[i].hdr.raw();for(int j=r+1;j<len;j++) s[i].hdr.add(s1[j]);
	}
	sort(s+1,s+1+n,cmpi);for(int i=1;i<=n;i++) s[i].lef=(i==1 || !(s[i].hdi==s[i-1].hdi))?i:s[i-1].lef;
	for(int i=1;i<=n;i++) sl[i]=s[i],sl[i].pre=i;
	sort(sl+1,sl+1+n,cmpl);
	for(int i=1;i<=n;i++) sr[i]=s[i],sr[i].pre=i;
	sort(sr+1,sr+1+n,cmpr);
	for(int i=1;i<=q;i++)
	{
		int len;
		cin >> s1 >> s2;
		if(s1.size()!=s2.size())
		{
			printf("0\n");
			continue;
		}
		len=s1.size();
		int l=n,r=-1;
		for(int j=0;j<len;j++) if(s1[j]!=s2[j]) l=min(l,j),r=max(r,j);
		tem.hdi.raw();
		for(int j=l;j<=r;j++) tem.hdi.add(s1[j]);
		for(int j=l;j<=r;j++) tem.hdi.add(s2[j]);
		printf("0\n");
	}
	return 0;
}
