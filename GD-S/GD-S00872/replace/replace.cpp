#include<bits/stdc++.h>
#define file(NAME)\
	freopen(NAME".in","r",stdin);\
	freopen(NAME".out","w",stdout);
#define ll long long
#define ull unsigned ll
#define rep(i,x,y) for(int i=x,y_=y;i<=y_;i++)
#define per(i,x,y) for(int i=y,x_=x;i>=x_;i--)
using namespace std;
const int N=2e5+5,S=5e6+5,M=30,K=131,P=998244353;
int n,q,l,u,v;
string a,b;
ull c;
unordered_map<ull,int> mp;
int m,s,rt[N],tr[S][M],t[S],fl[S],w;
int d[S],h;
int z;
int main()
{
	file("replace");
	cin>>n>>q;
	rep(i,1,n)
	{
		cin>>a>>b;
		if(a==b) continue;
		l=a.length(),a='#'+a,b='#'+b;
		rep(j,1,l) if(a[j]!=b[j]) {u=j;break;}
		per(j,1,l) if(a[j]!=b[j]) {v=j;break;}
		c=0;
		rep(j,u,v) c=c*K+a[j]-'a'+1;
		c=c*173;
		rep(j,u,v) c=c*K+b[j]-'a'+1;
		if(mp[c]==0) mp[c]=++m,rt[m]=++s;
		w=rt[mp[c]];
		rep(j,1,u-1)
		{
			if(tr[w][a[j]-'a']==0) tr[w][a[j]-'a']=++s;
			w=tr[w][a[j]-'a'];
		}
		if(tr[w][26]==0) tr[w][26]=++s;
		w=tr[w][26];
		rep(j,v+1,l)
		{
			if(tr[w][a[j]-'a']==0) tr[w][a[j]-'a']=++s;
			w=tr[w][a[j]-'a'];
		}
		t[w]++;
	}
	rep(i,1,m)
	{
		u=v=0;
		fl[rt[i]]=rt[i];
		rep(j,0,26)
		{
			if(tr[rt[i]][j]==0) tr[rt[i]][j]=rt[i];
			else d[++v]=tr[rt[i]][j],fl[d[v]]=rt[i];
		}
		while(u<v)
		{
			u++;
			rep(j,0,26)
			{
				if(tr[d[u]][j]==0) tr[d[u]][j]=tr[fl[d[u]]][j];
				else fl[tr[d[u]][j]]=tr[fl[d[u]]][j],d[++v]=tr[d[u]][j];
			}
		}
		rep(j,1,v) t[d[j]]+=t[fl[d[j]]];
	}
	rep(i,1,q)
	{
		cin>>a>>b,l=a.length(),a='#'+a,b='#'+b;
		rep(j,1,l) if(a[j]!=b[j]) {u=j;break;}
		per(j,1,l) if(a[j]!=b[j]) {v=j;break;}
		c=0;
		rep(j,u,v) c=c*K+a[j]-'a'+1;
		c=c*173;
		rep(j,u,v) c=c*K+b[j]-'a'+1;
		if(mp[c]==0) {printf("0\n");continue;}
		w=rt[mp[c]];
		rep(j,1,u-1) w=tr[w][a[j]-'a'];
		w=tr[w][26],z=t[w];
		rep(j,v+1,l) w=tr[w][a[j]-'a'],z+=t[w];
		printf("%d\n",z);
	}
	return 0;
}
