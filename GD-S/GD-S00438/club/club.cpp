#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int T;
long long ans;
long long n;

struct c {
	long long a, b, c;
	long long f, s, t;
	long long ma;
};

vector<c> f;
int vis[14];

bool cmp(c a,c b) {
	if(a.f==b.f) {
		if(a.s==b.s) {
			return a.t>b.t;
		}
		return a.s>b.s;
	}
	return a.f>b.f;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		f.resize(n+10);
		int maxn=n/2;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
			long long t=max(f[i].a,f[i].b);
			t=max(t,f[i].c);
			if(t==f[i].a) {
				f[i].f=1;
				int t2=max(f[i].b,f[i].c);
				if(t2==f[i].b) {
					f[i].s=2;
					f[i].t=3;
				} else {
					f[i].s=3;
					f[i].t=2;
				}
			} else if(t==f[i].b) {
				f[i].f=2;
				int t2=max(f[i].a,f[i].c);
				if(t2==f[i].a) {
					f[i].s=1;
					f[i].t=3;
				} else {
					f[i].s=3;
					f[i].t=1;
				}
			} else if(t==f[i].c) {
				f[i].f=3;
				int t2=max(f[i].a,f[i].b);
				if(t2==f[i].a) {
					f[i].s=1;
					f[i].t=2;
				} else {
					f[i].s=2;
					f[i].t=1;
				}
			}
		}
		sort(f.begin()+1,f.begin()+1+n,cmp);
		for(int i=1;i<=n;i++) {
			if(vis[f[i].f]<=(n/2)) {
				ans+=f[i].f;
			} else if(vis[f[i].s]<=(n/2)) {
				ans+=f[i].s;
			} else if(vis[f[i].t]<=(n/2)) {
				ans+=f[i].t;
			} 
		}
		cout<<ans;
	}
	return 0;
} 
