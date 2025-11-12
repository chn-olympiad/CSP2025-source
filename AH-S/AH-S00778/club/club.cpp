#include <bits/stdc++.h>
using namespace std;
struct person {
	long long s[4],num;
	bool f=false;
}a[100010];
long long t,n,ans,d[4],m1,m2;
bool check (person a,person b) {
	return a.num>b.num;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;
		ans=0;
		d[1]=d[2]=d[3]=0;
		m1=m2=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			a[i].f=false;
		}
		for (int i=1;i<=n;i++) {
			a[i].num=min(a[i].s[1]-a[i].s[2],a[i].s[1]-a[i].s[3]);
		}
		sort (a+1,a+n+1,check);
		for (int i=1;i<=n/2&&a[i].num>=0;i++) {
			if (a[i].f==false) {
				ans+=a[i].s[1];
				a[i].f=true;
				d[1]++;
			}
		}
		for (int i=1;i<=n;i++) {
			a[i].num=min(a[i].s[2]-a[i].s[1],a[i].s[2]-a[i].s[3]);
		}
		sort (a+1,a+n+1,check);
		for (int i=1;i<=n/2&&a[i].num>=0;i++) {
			if (a[i].f==false) {
				ans+=a[i].s[2];
				a[i].f=true;
				d[2]++;
			}
		}
		for (int i=1;i<=n;i++) {
			a[i].num=min(a[i].s[3]-a[i].s[2],a[i].s[3]-a[i].s[1]);
		}
		sort (a+1,a+n+1,check);
		for (int i=1;i<=n/2&&a[i].num>=0;i++) {
			if (a[i].f==false) {
				ans+=a[i].s[3];
				a[i].f=true;
				d[3]++;
			}
		}
		for (int i=1;i<=3;i++) {
			if (d[i]<n/2) {
				if (m1==0) {
					m1=i;
				} else {
					m2=i;
				}
			}
		}
		for (int i=1;i<=n;i++) {
			a[i].num=a[i].s[m1]-a[i].s[m2];
		}
		sort (a+1,a+n+1,check);
		for (int i=1;i<=n&&a[i].num>=0&&d[m1]<=n/2;i++) {
			if (a[i].f==false) {
				ans+=a[i].s[m1];
				d[m1]++;
			}
		}
		for (int i=1;i<=n;i++) {
			a[i].num=a[i].s[m2]-a[i].s[m1];
		}
		sort (a+1,a+n+1,check);
		for (int i=1;i<=n&&a[i].num>=0&&d[m2]<=n/2;i++) {
			if (a[i].f==false) {
				ans+=a[i].s[m2];
				d[m2]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
