#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
ll mc[5000010];
string s1[200010],s2[200010];
vector<ll> has1[200010],has2[200010];
int len1[200010],cl[200010],cr[200010];
string t1,t2;
vector<ll> has3,has4;
const ll mod=912345739,bas=71;
inline ll query1(int l,int r)
{
	r++;
	return ((has3[r]-has3[l]*mc[r-l]%mod)%mod+mod)%mod;
}
inline ll query2(int l,int r)
{
	r++;
	return ((has4[r]-has4[l]*mc[r-l]%mod)%mod+mod)%mod;
}
inline ll query3(int l,int r,int p)
{
	r++;
	return ((has1[p][r]-has1[p][l]*mc[r-l]%mod)%mod+mod)%mod;
}
inline ll query4(int l,int r,int p)
{
	r++;
	return ((has2[p][r]-has2[p][l]*mc[r-l]%mod)%mod+mod)%mod;
}
inline bool check(int l1,int r1,int l2,int r2,int p)
{
	return (query1(l1,r1)==query3(l2,r2,p)&&query2(l1,r1)==query4(l2,r2,p));
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mc[0]=1;
	for(register int i=1;i<=5e6;i++) mc[i]=mc[i-1]*bas%mod;
	scanf("%d%d",&n,&q);
	for(register int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i],len1[i]=s1[i].size();
		cl[i]=0,cr[i]=len1[i]-1;
		while(s1[i][cl[i]]==s2[i][cl[i]]) cl[i]++;
		while(s1[i][cr[i]]==s2[i][cr[i]]) cr[i]--;
		for(register int j=0;j<=len1[i];j++) has1[i].push_back(0),has2[i].push_back(0);
		for(register int j=1;j<=len1[i];j++) has1[i][j]=(has1[i][j-1]*bas%mod+s1[i][j-1])%mod,has2[i][j]=(has2[i][j-1]*bas%mod+s2[i][j-1])%mod;
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){puts("0");continue;}
		int len2=t1.size();
		int l=0,r=len2-1;
		while(t1[l]==t2[l]) l++;
		while(t1[r]==t2[r]) r--;
		has3.clear(),has4.clear();
		for(register int j=0;j<=len2;j++) has3.push_back(0),has4.push_back(0);
		for(register int j=1;j<=len2;j++) has3[j]=(has3[j-1]*bas%mod+t1[j-1])%mod,has4[j]=(has4[j-1]*bas%mod+t2[j-1])%mod;
		int ans=0;
		for(register int i=1;i<=n;i++)
		{
			if(!check(l,r,cl[i],cr[i],i)) continue;
			int ql=l-cl[i],qr=r+(len1[i]-1-cr[i]);
			if(ql<0||qr>=len2) continue;
			if(check(ql,qr,0,len1[i]-1,i)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
