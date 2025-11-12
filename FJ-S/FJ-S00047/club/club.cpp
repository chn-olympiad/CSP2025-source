#include <bits/stdc++.h>
#define MAXN 200011
using namespace std;
int T,n,ans,cp,cq,cr;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct node{
	int p,q,r,maxf,maxs,id;
}a[MAXN];
vector<node>mp,mq,mr,most;
bool cmp(node a, node b) {
	return (a.maxf-a.maxs)<(b.maxf-b.maxs);
}
void solve() {
	for (int i=1;i<=n;i++) {
		if (a[i].id==1) cp++,mp.push_back(a[i]);
		if (a[i].id==2) cq++,mq.push_back(a[i]);
		if (a[i].id==3) cr++,mr.push_back(a[i]);
		ans+=a[i].maxf;
	}
	if (max(cp,max(cq,cr))*2<=n) return ;
	if ((int)mp.size()*2>n) most=mp;
	if ((int)mq.size()*2>n) most=mq;
	if ((int)mr.size()*2>n) most=mr;
	sort(most.begin(),most.end(),cmp);
	for (int i=0;i<(int)most.size()-n/2;i++) {
		ans-=most[i].maxf-most[i].maxs;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		ans=0;
		cp=cq=cr=0;
		mp.clear(),mq.clear(),mr.clear();
		n=read();
		for (int i=1;i<=n;i++) {
			a[i].p=read(),a[i].q=read(),a[i].r=read();
			if (a[i].p>=a[i].q&&a[i].q>=a[i].r) a[i].maxf=a[i].p,a[i].maxs=a[i].q,a[i].id=1;
			if (a[i].p>=a[i].r&&a[i].r>=a[i].q) a[i].maxf=a[i].p,a[i].maxs=a[i].r,a[i].id=1;
			if (a[i].q>=a[i].p&&a[i].p>=a[i].r) a[i].maxf=a[i].q,a[i].maxs=a[i].p,a[i].id=2;
			if (a[i].q>=a[i].r&&a[i].r>=a[i].p) a[i].maxf=a[i].q,a[i].maxs=a[i].r,a[i].id=2;
			if (a[i].r>=a[i].q&&a[i].q>=a[i].p) a[i].maxf=a[i].r,a[i].maxs=a[i].q,a[i].id=3;
			if (a[i].r>=a[i].p&&a[i].p>=a[i].q) a[i].maxf=a[i].r,a[i].maxs=a[i].p,a[i].id=3;
		}
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
