#include<bits/stdc++.h>
using namespace std;
int n,zd;
int x[100005],z[100005],z[100005];

void test(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
	}
	zd=n/2;
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	sort(z+1,z+1+n);
	
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		test();
	}
	return 0;
}
/*	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].x<a[j].x){
				xa=a[i].x;
				a[i].x=a[j].x;
				a[j].x=xa;
			}
			if(a[i].y<a[j].y){
				ya=a[i].y;
				a[i].y=a[j].y;
				a[j].y=ya;
			}if(a[i].z<a[j].z){
				za=a[i].z;
				a[i].z=a[j].z;
				a[j].z=za;
			}
		}
	}
