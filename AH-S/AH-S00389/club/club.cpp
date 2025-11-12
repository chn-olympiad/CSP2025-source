#include<bits/stdc++.h>
using namespace std;
int t,n,nmx,xn,y1n,zn,sum;
struct Node{
	int x,y,z,ma,sma;
	int xy,yx,xz,zx,yz,zy;
}a[100010];
bool cmp1 (Node q,Node w){
	return min(q.xy,q.xz)<min(w.xy,w.xz);
}
bool cmp2 (Node q,Node w){
	return min(q.yx,q.yz)<min(w.yx,w.yz);
}
bool cmp3 (Node q,Node w){
	return min(q.zx,q.zy)<min(w.zx,w.zy);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		xn=0,y1n=0,zn=0,sum=0;
		cin>>n;
		nmx=n/2;
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xy=a[i].x-a[i].y;
			a[i].yx=a[i].y-a[i].x;
			a[i].xz=a[i].x-a[i].z;
			a[i].zx=a[i].z-a[i].x;
			a[i].zy=a[i].z-a[i].y;
			a[i].yz=a[i].y-a[i].z;
			a[i].ma=max(a[i].x,max(a[i].y,a[i].z));
			if (a[i].z>=a[i].x&&a[i].z>=a[i].y){
				a[i].sma=3;
			}
			if (a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].sma=2;
			}
			if (a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].sma=1;
			}
		}
		for (int i=1;i<=n;i++){
			sum+=a[i].ma;
			if (a[i].sma==1){
				xn++;
			}
			if (a[i].sma==2){
				y1n++;
			}
			if (a[i].sma==3){
				zn++;
			}
		}
		while (xn>nmx){
			sort(a+1,a+n+1,cmp1);
			for (int i=1;xn>nmx;i++){
				if (a[i].sma==1){
					sum-=min(a[i].xy,a[i].xz);
					xn--;
				}
			}
		}
		while (y1n>nmx){
			sort(a+1,a+n+1,cmp2);
			for (int i=1;y1n>nmx;i++){
				if (a[i].sma==2){
					sum-=min(a[i].yx,a[i].yz);
					y1n--;
				}
			}
		}
		while (zn>nmx){
			sort(a+1,a+n+1,cmp3);
			for (int i=1;zn>nmx;i++){
				if (a[i].sma==3){
					sum-=min(a[i].zx,a[i].zy);
					zn--;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//RP++
