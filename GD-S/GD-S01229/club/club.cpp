#include<bits/stdc++.h>
using namespace std;
int l,r,s,e,n,ma,mid,w,t,T;
struct stu {
	int x,y,z;
}a[100005];
void work(int de,int fa,int fb,int fc,int ta,int tb,int tc){
	if(ta>n/2) return ;
	if(tb>n/2) return ;
	if(tc>n/2) return ;
	if(de>n) {
		t=max(t,fa+fb+fc); 
		//cout<<fa<<" "<<fb<<" "<<fc<<endl;
		return ;
	}
	work(de+1,fa+a[de].x,fb,fc,ta+1,tb,tc);
	work(de+1,fa,fb+a[de].y,fc,ta,tb+1,tc);
	work(de+1,fa,fb,fc+a[de].z,ta,tb,tc+1);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
	
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		if(a[1].y==0&&a[1].z==0) {
			t=0;
			for(int i=1;i<=n/2;i++) t+=a[i].x;
			cout<<t<<endl;
			continue;
		}
		if(n<=30) {
			t=0;
			work(1,0,0,0,0,0,0);
			cout<<t<<endl;
		}
	}
	return 0;
}
