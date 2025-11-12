#include<cstdio>
#include<algorithm>
using namespace std;
struct A{ int x,y,z,su,id; }a[100001];
inline bool cmp(A q,A p) { return q.su>p.su; } 
int t,n,s[3],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int rp=1;rp<=t;rp++) {
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].su=a[i].x+a[i].y+a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i) {
			if(a[i].x>a[i].y&&a[i].x>a[i].z) {
				if(s[0]>=n/2) {
					if(a[i].y>a[i].z){
						if(s[1]>=n/2) s[2]++,a[i].id=3;
						else s[1]++,a[i].id=2;
					}
					else {
						if(s[2]>=n/2) s[1]++,a[i].id=2;
						else s[2]++,a[i].id=3;
					}
				}
				else s[0]++,a[i].id=1;
			} //x最大 
			if(a[i].y>a[i].x&&a[i].y>a[i].z) {
				if(s[1]>=n/2) {
					if(a[i].x>a[i].z) {
						if(s[0]>=n/2) s[2]++,a[i].id=3;
						else s[0]++,a[i].id=1;
					}
					else {
						if(s[2]>=n/2) s[0]++,a[i].id=1;
						else s[2]++,a[i].id=3;
					}
				}
				else s[1]++,a[i].id=2;
			} //y最大
			if(a[i].z>a[i].x&&a[i].z>a[i].y) {
				if(s[2]>=n/2) {
					if(a[i].x>a[i].y) {
						if(s[0]>=n/2) s[1]++,a[i].id=2;
						else s[0]++,a[i].id=1;
					}
					else {
						if(s[1]>=n/2) s[0]++,a[i].id=1;
						else s[1]++,a[i].id=2;
					}
				}
				else s[2]++,a[i].id=3;
			} 
		}
		for(int i=1;i<=n;++i) {
			if(a[i].id==1) ans+=a[i].x;
			else if(a[i].id==2) ans+=a[i].y;
			else ans+=a[i].z;
		}
		printf("%d\n",ans);
	}

	return 0;
}
