#include<bits/stdc++.h>
using namespace std;
struct code{
	int x,y,z;
}a[500010];
int t;
int n;
bool b;
bool cmp1(code h,code j){
	return h.x>j.x;
}
bool cmp2(code h,code j){
	return h.y>j.y;
}
bool cmp3(code h,code j){
	return h.z>j.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				b=true;
			}
		}
		if(b==false){
			sort(a+1,a+n+1,cmp1);
			cout<<a[1].x+a[2].x;
		}
		else if(n==2){
			cout<<max(a[1].x,a[2].x)+max(a[1].y,a[2].y)+max(a[1].z,a[2].z);
		}
		else{
			int ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].y;
			}
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].z;
			}
			cout<<ans;
		}
	}
	return 0;
}
