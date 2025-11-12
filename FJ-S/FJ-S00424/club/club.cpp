#include<bits/stdc++.h>
using namespace std;
struct node {
	int x,y,z,h,d,p;
} a[100010];
int n,t;
long long ans;
int b[10],c[10];
bool cmp(node s1,node s2) {
	return s1.p<s2.p;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) a[i].h=a[i].x,a[i].d=1,c[1]++;
			else {
				if(a[i].y>=a[i].z&&a[i].y>=a[i].x) a[i].h=a[i].y,a[i].d=2,c[2]++;
				else a[i].h=a[i].z,a[i].d=3,c[3]++;
			}
		}
		if(c[1]>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i].d==1) {
					if(a[i].y>a[i].z) a[i].p=a[i].x-a[i].y;
					else a[i].p=a[i].x-a[i].z;
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n; i++) {
				if(a[i].d==1) {
					if(c[1]>n/2) {
						c[1]--;
						if(a[i].y>a[i].z) a[i].d=2;
						else a[i].d=3;
					}
					else break;
				}
			}
		}
		if(c[2]>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i].d==2) {
					if(a[i].x>a[i].z) a[i].p=a[i].y-a[i].x;
					else a[i].p=a[i].y-a[i].z;
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n; i++) {
				if(a[i].d==2) {
					if(c[2]>n/2) {
						c[2]--;
						if(a[i].x>a[i].z) a[i].d=1;
						else a[i].d=3;
					}
					else break;
				}
			}
		}
		if(c[3]>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i].d==3) {
					if(a[i].y>a[i].x) a[i].p=a[i].z-a[i].y;
					else a[i].p=a[i].z-a[i].x;
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n; i++) {
				if(a[i].d==3) {
					if(c[3]>n/2) {
						c[3]--;
						if(a[i].y>a[i].x) a[i].d=2;
						else a[i].d=1;
					}
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i].d==1) ans+=a[i].x;
			if(a[i].d==2) ans+=a[i].y;
			if(a[i].d==3) ans+=a[i].z;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
