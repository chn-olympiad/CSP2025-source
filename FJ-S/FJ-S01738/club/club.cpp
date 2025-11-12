#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
	bool f=1;
}a[N];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp1(node x,node y){
	return x.y>y.y;
}
bool cmp2(node x,node y){
	return x.z>y.z;
}
int ma=0;
long long ans=0;
int sx=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		sx=n;
		int sl=0;
		bool f1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			if(a[i].y==0&&a[i].z==0){
				f1=1;
			}else{
				f1=0;
				break;
			}
		}
		if(f1==1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(ma<n/2&&sx!=0){
					if(a[i].x<a[i].y||a[i].x<a[i].z){
						continue;
					}else{
						ans+=a[i].x;
						ma++;
						sx--;
						a[i].f=0;
					}
				}
			}
			ma=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(ma<n/2&&sx!=0){
					if(a[i].y<a[i].z||a[i].f==0){
						continue;
					}else{
						ans+=a[i].y;
						ma++;
						sx--;
						a[i].f=0;
					}
				}
			}
			ma=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(ma<n/2&&sx!=0){
					if(a[i].f==0){
						continue;
					}else{
						ans+=a[i].z;
						ma++;
						sx--;
					}
				}
			}
			ma=0;
			cout<<ans<<endl;
			ans=0;
			for(int i=1;i<=n;i++){
				a[i].f=1;
			}
		}
	}
}
