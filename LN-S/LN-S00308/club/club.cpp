#include <bits/stdc++.h>
using namespace std;
// #define int unsigned long long

int n,cnt[4],ans,id;

struct node {
	int a[4],fmx,dmx,fmxid;
	bool operator < (const node &b) const {
		if (this->fmxid!=b.fmxid) return this->fmxid<b.fmxid;
		return this->dmx<b.dmx;
	}
}p[100010];

int FMAX(int a,int b,int c) {
	if (max(max(a,b),c)==a) return a;
	if (max(max(a,b),c)==b) return b;
	if (max(max(a,b),c)==c) return c;
}
int FMAXID(int a,int b,int c) {
	if (max(max(a,b),c)==a) return 1;
	if (max(max(a,b),c)==b) return 2;
	if (max(max(a,b),c)==c) return 3;
}
int SMAX(int a,int b,int c) {
	// if (FMAX(a,b,c).second==1) return {max(b,c),(max(b,c)==b ? 2 : 3)};
	// if (FMAX(a,b,c).second==2) return {max(a,c),(max(a,c)==a ? 1 : 3)};
	// if (FMAX(a,b,c).second==3) return {max(a,b),(max(a,b)==a ? 1 : 2)};
	if (FMAXID(a,b,c)==1) return max(b,c);
	if (FMAXID(a,b,c)==2) return max(a,c);
	if (FMAXID(a,b,c)==3) return max(a,b);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;cin>>t;
	while (t--) {
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		ans=0;
		int tmp=n/2;
		for (int i=1;i<=n;i++) {
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
			// cout<<FMAX(p[i].a[1],p[i].a[2],p[i].a[3])<<" ";
			// cout<<FMAXID(p[i].a[1],p[i].a[2],p[i].a[3])<<" ";
			// cout<<SMAX(p[i].a[1],p[i].a[2],p[i].a[3])<<"\n";
			
			p[i].fmx=FMAX(p[i].a[1],p[i].a[2],p[i].a[3]);
			cnt[FMAXID(p[i].a[1],p[i].a[2],p[i].a[3])]++;
			p[i].dmx=p[i].fmx-SMAX(p[i].a[1],p[i].a[2],p[i].a[3]);
			ans+=p[i].fmx;
			p[i].fmxid=FMAXID(p[i].a[1],p[i].a[2],p[i].a[3]);
			// cout<<ans<<" ";
		}
		id=0;
		if (cnt[1]>tmp) id=1;
		else if (cnt[2]>tmp) id=2;
		else if (cnt[3]>tmp) id=3;
		// cout<<id<<"\n";
		if (id) {
			sort(p+1,p+n+1);
			int pos;
			for (pos=1;pos<=n and p[pos].fmxid!=id;pos++) ;
			// cout<<p[pos].fmxid<<" ";
			// cout<<"\n";
			// for (int i=1;i<=n;i++) cout<<p[i].fmx<<" "<<p[i].dmx<<" "<<p[i].fmxid<<"\n";
			// cout<<"ans:"<<ans<<" pos:"<<pos<<"\n";
			for (int i=pos;i<=pos+cnt[id]-tmp-1;i++) ans-=p[i].dmx;
		}
		cout<<ans<<"\n";
	}
	return 0;
}