#include <bits/stdc++.h>
#define ll int
#define endl putchar(10)
using namespace std; ll read() {ll x=0, f=1; char c=getchar();
while(c<48 || c>57) f=c=='-'?-1:1, c=getchar(); while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(ll x)
{ll st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);}
ll n,k,m,f,g,ans; string s,t,p[2001],q[2001],x,y;
unordered_map<string,vector<string>> bz;

ll main()
{
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	n=read(); k=read(); for(ll i=1; i<=n; ++i)
	cin>>s>>t, bz[s].push_back(t);
	
	while(k--)
	{
		cin>>s>>t; m=s.size(); if(m!=t.size()) {write(0); endl; continue;}
		ans=0; p[0]=s[0]; q[m-1]=s[m-1]; for(ll i=1; i<m; ++i)
		p[i]=p[i-1]+s[i]; for(ll i=m-2; i>=0; --i) q[i]=s[i]+q[i+1];
		for(ll i=0; i<m; ++i) {x=""; for(ll j=i; j<m; ++j) {x+=s[j];
		if(!bz[x].empty()) {for(string c:bz[x]) y=(i?p[i-1]:"")+
		c+q[j+1], ans+=y==t;}}} write(ans); endl;
	}

	return 0;
}
