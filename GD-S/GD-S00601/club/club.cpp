#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,cnt;
struct lj {
	int op,s,mx,mx2;
}a[N];
bool cmp(lj a,lj b) {
	if(a.op==b.op) return a.s>b.s;
	return a.op<b.op;
}
void solve() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int ca,cb,cc;
	    scanf("%d%d%d",&ca,&cb,&cc);
		if(cb>ca) a[i].mx=cb,a[i].mx2=ca;
		else a[i].mx=ca,a[i].mx2=cb;
		if(cc>a[i].mx) a[i].mx2=a[i].mx,a[i].mx=cc;
		else if(cc>a[i].mx2) a[i].mx2=cc;
		a[i].s=a[i].mx-a[i].mx2;
		if(ca>=cb&&ca>=cc) a[i].op=1;
		if(cb>ca&&cb>=cc) a[i].op=2;
		if(cc>cb&&cc>ca) a[i].op=3;
	}
	sort(a+1,a+n+1,cmp);
	ans=0;
	for(int i=1;i<=n;i++) {
		if(a[i].op!=a[i-1].op) cnt=0;
		if(cnt<n/2) {
			cnt++;
			ans+=a[i].mx;
		}
		else ans+=a[i].mx2;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) a[i].mx=a[i].mx2=a[i].op=a[i].s=0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0; 
}
