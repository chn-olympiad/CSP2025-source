#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z,maxx,minn,mxn;
} a[100010];
bool cmp(node p,node q){
	if(p.maxx-p.mxn>q.maxx-q.mxn) return p.maxx-p.mxn>q.maxx-q.mxn;
	else if(p.mxn-p.minn>q.mxn-q.minn) return p.mxn-p.minn>q.mxn-q.minn;
	return p.maxx>q.maxx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,xx=0,yy=0,zz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxx=max(a[i].x,max(a[i].y,a[i].z));
			a[i].minn=min(a[i].x,min(a[i].y,a[i].z));
			a[i].mxn=a[i].x+a[i].y+a[i].z-a[i].maxx-a[i].minn;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].maxx==a[i].x) {
				if(xx<n/2) {
					ans+=a[i].x;
					xx++;
				}
				else ans+=a[i].mxn;
			}
			if(a[i].maxx==a[i].y) {
				if(yy<n/2) {
					ans+=a[i].y;
					yy++;
				}
				else ans+=a[i].mxn;
			}
			if(a[i].maxx==a[i].z) {
				if(zz<n/2) {
					ans+=a[i].z;
					zz++;
				}
				else ans+=a[i].mxn;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
