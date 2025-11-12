//GZ-S00466 贵阳中天中学 陈彬垚
#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+10;
int a[N],b[N],c[N];
int a1,b1,c1,ans,zd;
int a2,b2,c2;
int n;
void df(int q,int w,int e) {
	for(int i=1; i<=3; i++) {
		zd=max(q,max(w,e));
		if(zd==q) {
			if(a1<n/2) {
				ans+=q;
				a1++;
				return;
			} else {
				q=0;
			}
		} else if(zd==w) {
			if(b1<n/2) {
				ans+=w;
				b1++;
				return;
			} else {
				w=0;
			}
		}
		else {
			if(c1<n/2) {
				ans+=e;
				c1++;
				return;
			} else {
				e=0;
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			df(a[i],b[i],c[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
