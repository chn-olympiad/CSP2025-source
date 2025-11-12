#include<bits/stdc++.h>
using namespace std;
struct p {
	int maxx;
	int smaxx;
	int t;
	int ts;
} a[114514];
int n,m,t;
bool cmp(p a,p b) {
	return a.maxx-a.smaxx>b.maxx-b.smaxx;
}
int main() {
	ifstream cin("club.in");
	ofstream cout("club.out");
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1,x,y,z; i<=n; i++) {
			cin>>x>>y>>z;
			if(x>=y&&x>=z&&y>=z) {
				a[i].maxx=x,a[i].smaxx=y,a[i].t=1,a[i].ts=2;
			} else if(x>=y&&x>=z&&z>=y) {
				a[i].maxx=x,a[i].smaxx=z,a[i].t=1,a[i].ts=3;
			} else if(y>=x&&y>=z&&z>=x) { 
				a[i].maxx=y,a[i].smaxx=z,a[i].t=2,a[i].ts=3;
			} else if(y>=x&&y>=z&&x>=z) {  
				a[i].maxx=y,a[i].smaxx=x,a[i].t=2,a[i].ts=1;
			} else if(z>=x&&z>=y&&y>=x) { 
				a[i].maxx=z,a[i].smaxx=y,a[i].t=3,a[i].ts=2;
			} else if(z>=x&&z>=y&&x>=y) {  
				a[i].maxx=z,a[i].smaxx=x,a[i].t=3,a[i].ts=1;
			}
		}
		sort(a+1,a+1+n,cmp);
		int tot[5];
		tot[1]=0,tot[2]=0,tot[3]=0;
		int ans=0;
		int n1=n/2;
		for(int i=1; i<=n; i++) {
			int bh=a[i].t,cbh=a[i].ts;
			if(tot[bh]<n1) {
				tot[bh]++;
				ans+=a[i].maxx;
			} else {
				tot[cbh];
				ans+=a[i].smaxx;
			}
		}
		cout<<ans<<endl;
	}
	cin.close();
	cout.close();
	return 0;
}
