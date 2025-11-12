#include<bits/stdc++.h>
using namespace std;
#define pr pair<long long,long long>
const int N=5e6+5,M=2e5+5,mod1=1e9+7,K=5e6;
int n,q,m,ans[M],fl,pw[N],ss1[M],tt1[M];char s[N],t[N];vector<int>ss[M],tt[M];
struct node {
	int sm1,tm1;
	bool operator<(const node &u) const {
		if(sm1!=u.sm1) return sm1<u.sm1;
		if(tm1!=u.tm1) return tm1<u.tm1;
		return 0;
	}
	bool operator==(const node &u) const {return sm1==u.sm1&&tm1==u.tm1;}
};
struct node2 {
	node z;int id,x,y,h;
	bool operator<(const node2 &u) const {return z==u.z?(x!=u.x?x<u.x:id<u.id):z<u.z;}
}a[M<<1],b[M<<1];
inline node2 calc(int id) {
	int l=1,r=strlen(s+1);
	while(s[l]==t[l]) ++l;
	while(s[r]==t[r]) --r;
	node a;a.sm1=0,a.tm1=0;
	for(int i=l;i<=r;++i) {
		a.sm1=(a.sm1*1ll*31+s[i]-'a')%mod1;
		a.tm1=(a.tm1*1ll*31+t[i]-'a')%mod1;
	}
	return {a,id,l-1,(int)strlen(s+1)-r,(int)strlen(s+1)};
}
int c[N];
inline void upd(int x) {for(;x<=K;x+=(x&-x)) ++c[x];return ;}
inline int query(int x) {int rs=0;for(;x;x-=(x&-x)) rs+=c[x];return rs;}
inline void cl(int x) {for(;x<=K;x+=(x&-x)) c[x]=0;return ;}
inline void work() {
	if(!fl) {
		for(int i=1;i<=m;++i) {
			if(b[i].id<0) upd(b[i].y+1);
			else ans[b[i].id]=query(b[i].y+1);
		}
		for(int i=1;i<=m;++i) if(b[i].id<0) cl(b[i].y+1);
		return ;
	}
	for(int i=1;i<=m;++i) if(b[i].id>0) for(int j=1;j<i;++j) if(b[j].id<0) {
		int l=b[i].x-b[j].x,r=b[i].x-b[j].x+b[j].h;
		int hs=(ss[b[i].id][r]-ss[b[i].id][l]*1ll*pw[b[j].h])%mod1;
		if(hs<0) hs+=mod1;
		if(hs!=ss1[-b[j].id]) continue;
		hs=(tt[b[i].id][r]-tt[b[i].id][l]*1ll*pw[b[j].h])%mod1;
		if(hs<0) hs+=mod1;
		if(hs!=tt1[-b[j].id]) continue;
		++ans[b[i].id];
	}
	return ;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw[0]=1;for(int i=1;i<N;++i) pw[i]=pw[i-1]*1ll*31%mod1;
	for(int i=1;i<=n;++i) {
		scanf("%s%s",s+1,t+1),a[i]=calc(-i);
		int h=strlen(s+1),cnt=0;
		for(int j=1;j<=h;++j) {
			ss1[i]=(ss1[i]*31ll+s[j]-'a')%mod1;
			tt1[i]=(tt1[i]*31ll+t[j]-'a')%mod1;
		}
		for(int j=1;j<=h;++j) if(s[j]!='a') {
			if(s[j]!='b') fl=1;
			else ++cnt;
		}
		if(cnt>1) fl=1;cnt=0;
		for(int j=1;j<=h;++j) if(t[j]!='a') {
			if(t[j]!='b') fl=1;
			else ++cnt;
		}
		if(cnt>1) fl=1;
	}
	for(int i=1;i<=q;++i) {
		scanf("%s%s",s+1,t+1),a[i+n]=calc(i);
		int h=strlen(s+1),cnt=0;
		for(int j=1;j<=h;++j) if(s[j]!='a') {
			if(s[j]!='b') fl=1;
			else ++cnt;
		}
		if(cnt>1) fl=1;cnt=0;
		for(int j=1;j<=h;++j) if(t[j]!='a') {
			if(t[j]!='b') fl=1;
			else ++cnt;
		}
		ss[i].resize(h+5);tt[i].resize(h+5);ss[i][0]=tt[i][0]=0;
		for(int j=1;j<=h;++j) {
			ss[i][j]=(ss[i][j-1]*31ll+s[j]-'a')%mod1;
			tt[i][j]=(tt[i][j-1]*31ll+t[j]-'a')%mod1;
		}
		if(cnt>1) fl=1;
	}
	sort(a+1,a+1+n+q);
	for(int i=1,j;i<=n+q;i=j+1) {
		for(j=i;a[j+1].z==a[j].z&&j<n+q;++j) ;m=0;
		for(int k=i;k<=j;++k) b[++m]=a[k];
		work();
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}