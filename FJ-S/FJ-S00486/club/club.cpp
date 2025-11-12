#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node {
	int x_90,y_90,z_90;
	int thjz_90;
	int lx_90;
} a[N];
int t,sumx_90=0,sumy_90=0,sumz_90=0;
long long ans=0;
bool cmp(node x,node y) {
	return x.thjz_90<y.thjz_90;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n;
		m=n/2;
		ans=0;
		sumx_90=0;
		sumy_90=0;
		sumz_90=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x_90>>a[i].y_90>>a[i].z_90;
		}
		for(int i=1; i<=n; i++) {
			a[i].thjz_90=max(max(a[i].x_90,a[i].y_90),a[i].z_90)-min(max(a[i].x_90,a[i].y_90),max(a[i].y_90,a[i].z_90));
			if(max(max(a[i].x_90,a[i].y_90),a[i].z_90)==a[i].x_90) {
				a[i].lx_90=1;
				sumx_90++;
			}
			if(max(max(a[i].x_90,a[i].y_90),a[i].z_90)==a[i].y_90) {
				a[i].lx_90=2;
				sumy_90++;
			}
			if(max(max(a[i].x_90,a[i].y_90),a[i].z_90)==a[i].z_90) {
				a[i].lx_90=3;
				sumz_90++;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1; i<=n; i++) {
			ans+=max(max(a[i].x_90,a[i].y_90),a[i].z_90);
		}
		if(sumx_90>m) {
			int cs_90=0;
			for(int i=1; i<=n; i++) {
				if(a[i].lx_90==1) {
//					cout<<ans<<' ';
					ans-=a[i].thjz_90;
					cs_90++;
//					cout<<ans<<"\n";
				}
				if(cs_90==sumx_90-m) {
					break;
				}
			}
		}
		if(sumy_90>m) {
			int cs_90=0;
			for(int i=1; i<=n; i++) {
				if(a[i].lx_90==2) {
//					cout<<ans<<' ';
					ans-=a[i].thjz_90;
					cs_90++;
//					cout<<ans<<"\n";
				}
				if(cs_90==sumy_90-m) {
					break;
				}
			}
		}
		if(sumz_90>m) {
			int cs_90=0;
			for(int i=1; i<=n; i++) {
				if(a[i].lx_90==3) {
//					cout<<ans<<' ';
					ans-=a[i].thjz_90;
					cs_90++;
//					cout<<ans<<"\n";
				}
				if(cs_90==sumz_90-m) {
					break;
				}
			}
		}
//		for(int i=1;i<=n;i++) cout<<a[i].thjz_90<<' ';
//		cout<<endl;
		cout<<ans<<"\n";
	}
	return 0;
}
