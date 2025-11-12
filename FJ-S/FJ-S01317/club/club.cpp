#include<bits/stdc++.h>
using namespace std;
int t,n,ans,sum1,sum2;
struct aa{
	int x;
	int y;
	int z;
	int mmax;
};
aa a[100005];
bool b1=1,b2=1;
bool cmp(aa a,aa b) {
	return a.mmax>b.mmax;
}
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mmax=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].z!=0) {
				b1=0;b2=0;
			}
			if(a[i].y!=0) {
				b1=0;
			}
		}
		sort(a+1,a+1+n,cmp);
		if(b1==1) {
			for(int i=1;i<=n/2;i++) {
				ans+=a[i].x;
			}
		} else if(b2==1) {
			for(int i=1;i<=n;i++) {
				if(a[i].mmax==a[i].x) {
					if(sum1<n/2) {
						ans+=a[i].x;
						sum1++;
					} else {
						ans+=a[i].y;
						sum2++;
					}
				} else if(a[i].mmax==a[i].y) {
					if(sum2<n/2) {
						ans+=a[i].y;
						sum2++;
					} else {
						ans+=a[i].x;
						sum1++;
					}
				}
			}
		}
		sum1=0;
		sum2=0;
//		for(int i=1;i<=n;i++) {
//			cout<<a[i].x<<a[i].y<<a[i].z<<"\n";
//		}
		cout<<ans<<"\n";
		ans=0;
		t--;
	}
	return 0;
}
