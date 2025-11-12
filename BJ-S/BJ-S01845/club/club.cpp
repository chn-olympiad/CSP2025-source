#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,pos;
} a[100005];
struct node2{
	int x,pos;
};
bool cmp2(node2 e,node2 f){
	return e.x<f.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].pos=i;
		}
		int cnx=0,cny=0,cnz=0,sum=0;
		node2 ax[100005],ay[100005],az[100005];
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				sum+=a[i].x;
				cnx++;
				ax[cnx].x=a[i].x-max(a[i].y,a[i].z);
			}else if(a[i].x<=a[i].y&&a[i].y>=a[i].z){
				sum+=a[i].y;
				cny++;
				ay[cny].x=a[i].y-max(a[i].x,a[i].z);
			}else{
				sum+=a[i].z;
				cnz++;
				az[cnz].x=a[i].z-max(a[i].y,a[i].x);
			}
		}
		if(cnx>n/2){
			sort(ax+1,ax+cnx+1,cmp2);
			for(int i=1;i<=cnx-n/2;i++){
				sum-=ax[i].x;
			}
		}
		if(cny>n/2){
			sort(ay+1,ay+cny+1,cmp2);
			for(int i=1;i<=cny-n/2;i++){
				sum-=ay[i].x;
			}
		}
		if(cnz>n/2){
			sort(az+1,az+cnz+1,cmp2);
			for(int i=1;i<=cnz-n/2;i++){
				sum-=az[i].x;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
