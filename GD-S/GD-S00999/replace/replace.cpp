#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define b1 917
#define b2 317
#define p1 666666667
#define p2 998244353
#define ll long long
using namespace std;
int n,m,q;
char s1[2010],s2[2010];
ll pw1[4010],pw2[4010];
struct pr {
	ll x,y;
	inline friend pr operator+(pr u,int v) {
		u.x=(u.x*b1+v)%p1;
		u.y=(u.y*b2+v)%p2;
		return u;
	}
	inline friend bool operator<(pr u,pr v) {
		if(u.x!=v.x) return u.x<v.x;
		return u.y<v.y;
	}
}ht[4010];
map<pr,int>mp;
pr mis(int l,int r) {
	pr p;
	p.x=((ht[r].x-ht[l].x*pw1[r-l])%p1+p1)%p1;
	p.y=((ht[r].y-ht[l].y*pw2[r-l])%p2+p2)%p2;
	return p;
}
void work() {
	scanf("%s%s",s1+1,s2+1);
	int len=strlen(s1+1),len2=strlen(s2+1);
	if(len!=len2) {
		puts("0");
		return;
	}
	m=0;
	int P=-1,Q;
	for(int i=1;i<=len;++i) {
		if(s1[i]!=s2[i]&&P==-1) P=m;
		++m;
		ht[m]=ht[m-1]+int(s1[i]-'a');
		++m;
		ht[m]=ht[m-1]+int(s2[i]-'a');
		++m;
		ht[m]=ht[m-1]+26;
		if(s1[i]!=s2[i]) Q=m;
	}
	int ans=0;
	for(int i=0;i<=P;++i)
		for(int j=Q;j<=m;++j) ans+=mp[mis(i,j)];
	printf("%d\n",ans);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<4010;++i) {
		pw1[i]=pw1[i-1]*b1%p1;
		pw2[i]=pw2[i-1]*b2%p2;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) {
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		pr hs={0,0};
		for(int j=1;j<=len;++j) {
			hs=hs+int(s1[j]-'a');
			hs=hs+int(s2[j]-'a');
			hs=hs+26;
		}
		++mp[hs];
	}
	while(q--) work();
	return 0;
}
