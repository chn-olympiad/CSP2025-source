#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int pa,pb,pc,n;
int max1(int x,int y,int z){
	return max(x,max(y,z));
}
int cmp1(node a,node b){
	return a.x-max(a.y,a.z)>b.x-max(b.y,b.z);
}
int cmp2(node a,node b){
	return a.y-max(a.x,a.z)>b.y-max(b.x,b.z);
}
int cmp3(node a,node b){
	return a.z-max(a.x,a.y)>b.z-max(b.x,b.y);
}
int da1(){
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].y,a[i].z);
	}
	return ans;
}
int da2(){
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].y;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].x,a[i].z);
	}
	return ans;
}
int da3(){
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].z;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].x,a[i].y);
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		pa=pb=pc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			pa+=(a[i].x==max1(a[i].x,a[i].y,a[i].z));
			pb+=(a[i].y==max1(a[i].x,a[i].y,a[i].z));
			pc+=(a[i].z==max1(a[i].x,a[i].y,a[i].z));
		}
		if(pa<=n/2&&pb<=n/2&&pc<=n/2){
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=max1(a[i].x,a[i].y,a[i].z);
			}
			cout<<ans<<endl;
		}else{
			if(pa>n/2)sort(a+1,a+1+n,cmp1);
			else if(pb>n/2)sort(a+1,a+1+n,cmp2);
			else if(pc>n/2)sort(a+1,a+1+n,cmp3);
			if(pa>n/2)cout<<da1()<<endl;
			else if(pb>n/2)cout<<da2()<<endl;
			else if(pc>n/2)cout<<da3()<<endl;
		}
	}
	return 0;
}
