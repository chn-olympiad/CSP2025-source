#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
	int id;
}a[100010];
int t,n;
bool cmp(Node x,Node y){
	if(x.id==y.id){
		if(x.id==1) return x.x>y.x;
		if(x.id==2) return x.y>y.y;
		if(x.id==3) return x.z>y.x;
	}
	else return x.id<y.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sx=0,sy=0,sz=0,tmpx=0,tmpy=0,tmpz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==0) tmpx++;
			if(a[i].y==0) tmpy++;
			if(a[i].z==0) tmpz++;
			if(a[i].x>a[i].y&&a[i].x>a[i].z) a[i].id=1,sx++;
			if(a[i].y>a[i].x&&a[i].y>a[i].z) a[i].id=2,sy++;
			if(a[i].z>a[i].x&&a[i].z>a[i].y) a[i].id=3,sz++;
			if(a[i].x==a[i].y&&a[i].x>a[i].z){
				if(sx>=sy) a[i].id=2,sy++;
				else a[i].id=1,sx++;
			}
			if(a[i].x==a[i].z&&a[i].x>a[i].y) {
				if(sx>=sz) a[i].id=3,sz++;
				else a[i].id=1,sx++;
			}
			if(a[i].y==a[i].z&&a[i].y>a[i].x) {
				if(sz>=sy) a[i].id=2,sy++;
				else a[i].id=3,sz++;
			}
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++) cout<<a[i].id<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
		if(tmpy==n&&tmpz==n){
//			cout<<1<<endl;
			long long ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
		}
		else if(tmpz==n){
//			cout<<2<<endl;
			long long ans=0;
			if(sx==n/2&&sy==n/2){
				cout<<21<<endl;
				for(int i=1;i<=n/2;i++) ans+=a[i].x;
				for(int i=n/2+1;i<=n;i++) ans+=a[i].y;
				cout<<ans<<endl;
			}
			if(sx>n/2){
//				cout<<22<<endl;
				for(int i=1;i<=n/2;i++) ans+=a[i].x;
				for(int i=n/2+1;i<=n;i++) ans+=a[i].y;
				cout<<ans<<endl;
			}
			else if(sy>n/2){
//				cout<<23<<endl;
				for(int i=1;i<=sx;i++) ans+=a[i].x;
				for(int i=sx+1;i<=sx+n/2;i++) ans+=a[i].y;
				for(int i=sx+n/2+1;i<=n;i++) ans+=a[i].x;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
