#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],aa=0,bb=0,cc=0,ans=0;
struct c {
	int a,b,c;
} r[100005];
bool cmp(c x,c y) {
	if(x.a==y.a) {
		if(x.b==y.b) return x.c>y.c;
		return x.b>y.b;
	}
	return x.a>y.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		aa=0,bb=0,cc=0,ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>r[i].a>>r[i].b>>r[i].c;
		sort(r+1,r+n+1,cmp);
		for(int i=1; i<=n; i++) {
			if(r[i].a>=r[i].b&&r[i].a>=r[i].c) {
				ans+=r[i].a;
				aa++;
				if(aa>n/2) {
					if(r[i-1].b+r[i].a>r[i-1].a+r[i].b) {
						ans-=r[i-1].a;
						ans+=r[i-1].b;
						bb++;
					} else {
						ans-=r[i].a;
						ans+=r[i].b;
					}
				}
			} else if(r[i].b>r[i].c&&r[i].b>r[i].a) {
				ans+=r[i].b;
				bb++;
				if(bb>n/2) {
					if(r[i-1].c+r[i].b>r[i-1].b+r[i].c) {
						ans-=r[i-1].b;
						ans+=r[i-1].c;
						cc++;
					} else {
						ans-=r[i].b;
						ans+=r[i].c;
					}
				}
			} else ans+=r[i].c;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
