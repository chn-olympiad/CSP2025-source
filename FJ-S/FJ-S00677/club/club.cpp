#include<bits/stdc++.h>
using namespace std;
struct coco{
	int x,y,z;
}a[1234567];
bool cmp1(coco x,coco y){
	return x.x>y.x;
}
bool cmp2(coco x,coco y){
	return x.y>y.y;
}
bool cmp3(coco x,coco y){
	return x.z>y.z;
}
int v[1234567];
int t;
int sum;
int id,id2,id3;
int n;
int m1,m2,m3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].x=0;
			a[i].y=0;
			a[i].z=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int j=1;j<n/2;j++){
			sort(a+1,a+n+1,cmp1);
			sum+=a[1].x;
			a[1].x=0;
			a[1].y=0;
			a[1].z=0;
			
			sort(a+1,a+n+1,cmp2);
			sum+=a[1].y;
			a[1].x=0;
			a[1].y=0;
			a[1].z=0;
			
			sort(a+1,a+n+1,cmp3);
			sum+=a[1].z;
			a[1].x=0;
			a[1].y=0;
			a[1].z=0;
		}
		cout<<sum;
		sum=0;
		
	}return 0;
}

