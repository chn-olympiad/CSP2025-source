#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int T,n;
struct node {
	int d[4],v;
}a[N];
bool v[N];
bool cmp(node p, node q) {
	return p.d[2]-p.d[1]<q.d[2]-q.d[1];
}
bool cmp1(node p, node q) {
	return p.d[1]>q.d[1];
}
bool cmp2(node p, node q) {
	return p.d[2]>q.d[2];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--) {
		cin>>n;
		bool f2=true,f3=true;
		for (int i=1; i<=n; i++) {
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			a[i].v=false;
			if (a[i].d[2]) f2=false;
			if (a[i].d[3]) f3=false;
		}
		if (f2 && f3) {
			sort(a+1,a+n+1,cmp1);
			long long ans=0;
			for (int i=1; i<=n/2; i++) ans=ans+a[i].d[1];
			cout<<ans<<endl;
			continue;
		}
		else if (!f2 && f3) {
			sort(a+1,a+n+1,cmp);
			long long ans=0;
			for (int i=1; i<=n/2; i++) ans=ans+a[i].d[1];
			for (int i=n/2+1; i<=n; i++) ans=ans+a[i].d[2];
			cout<<ans<<endl;
			continue;
		}
		else {
			sort(a+1,a+n+1,cmp1);
			int x=n/2;
			long long ans=0;
			for (int i=1; i<=n && x--; i++) {
				ans=ans+a[i].d[1];
				a[i].v=true;
			}
			sort(a+1,a+n+1,cmp2);
			x=n/2;
			for (int i=1; i<=n && x--; i++) {
				if (!a[i].v && a[i].d[2]>=a[i].d[3]) {
					ans=ans+a[i].d[2];
					a[i].v=true;
				}
			}
			for (int i=1; i<=n; i++)
				if (!a[i].v) ans=ans+a[i].d[3];
			cout<<ans<<endl;
		}
	}
	return 0;
}
