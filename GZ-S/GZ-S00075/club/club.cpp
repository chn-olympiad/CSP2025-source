/*GZ-S00075 毕节梁才学校 卢麟一*/
#include<bits/stdc++.h>
using namespace std;
/*bool v[100010];
typedef pair<int,int> PII;*/
struct TT {
	int x;
	int y;
	int z;
	int f;
};
int t;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp1(TT oo, TT pp) {
	return oo.x<pp.x;
}
bool cmp2(TT oo, TT pp) {
	return oo.y<pp.y;
}
bool cmp3(TT oo, TT pp) {
	return oo.z<pp.z;
}
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0) {
		t--;
		int n=0,ans=0,diji[100010],m=0;
		TT a[100010];
		int di1,di2,di3,oi1=0,oi2=0,oi3=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			int yz=max(a2,a3),xz=max(a1,a3),big=max(xz,yz),xy=0;
			yz=big-a1;
			xz=big-a2;
			xy=big-a3;
			a[i].x=yz,a[i].y=xz,a[i].z=xy,a[i].f=big;
		}
		sort(a+1,a+n+1,cmp1);
		while(oi1<=n/2) {
			oi1++;
			di1=-0x3f3f3f;
			int oop=0;
			for(int i=oi1; i<=n; i++) {
				int xy=a[i].x-a[i].y,xz=a[i].x-a[i].z;
				xy=max(xy,xz);
				di1=max(di1,xy);
				if(di1==xy) {
					oop=i;
				}
			}
			ans+=a[oop].f;
			a[oop].x=0;
			a[oop].y=0;
			a[oop].z=0;
			a[oop].f=0;
		}
		sort(a+1,a+n+1,cmp2);
		while(oi2<=n/2) {
			oi2++;
			di2=-0x3f3f3f;
			int oop=0;
			for(int i=oi2; i<=n; i++) {
				int xy=a[i].y-a[i].x,yz=a[i].y-a[i].z;
				xy=max(xy,yz);
				di2=max(di2,xy);
				if(di2==xy) {
					oop=i;
				}
			}
			ans+=a[oop].f;
			a[oop].x=0;
			a[oop].y=0;
			a[oop].z=0;
			a[oop].f=0;
		}
		sort(a+1,a+n+1,cmp3);
		while(oi3<=n/2) {
			oi3++;
			di3=-0x3f3f3f;
			int oop=0;
			for(int i=oi3; i<=n; i++) {
				int zx=a[i].z-a[i].x,zy=a[i].z-a[i].y;
				zx=max(zx,zy);
				di3=max(di3,zx);
				if(di3==zx) {
					oop=i;
				}
			}
			ans+=a[oop].f;
			a[oop].x=0;
			a[oop].y=0;
			a[oop].z=0;
			a[oop].f=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
