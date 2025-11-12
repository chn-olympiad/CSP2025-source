#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+7;
struct node{
	long long x,y,z;
}a[N];
int m(node a){
	return a.x+a.y+a.z-max(max(a.x,a.y),a.z)-min(min(a.x,a.y),a.z);
}
int cmp(node a,node b){
	return max(max(a.x,a.y),a.z)-m(a)>max(max(b.x,b.y),b.z)-m(b);
}
int cmp1(node a,node b){
	return max(a.x,a.y)>max(b.x,b.y);
}
int cmp2(node a,node b){
	return max(a.x,a.z)>max(b.x,b.z);
}
int cmp3(node a,node b){
	return max(a.z,a.y)>max(b.z,b.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,i,x,y,z,xx,yy,zz,ans=0;
	cin>>t;
	while(t--){
		ans=0,xx=0,yy=0,zz=0,x=0,y=0,z=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++){
			if(x==n/2){
				sort(a+i,a+n,cmp3);
				x++;xx=1;
			}
			if(y==n/2){
				sort(a+i,a+n,cmp2);
				y++;yy=1;
			}
			if(z==n/2){
				sort(a+i,a+n,cmp1);
				z++;zz=1;
			}
			if(xx==1){
				if(a[i].y>a[i].z){
					ans+=a[i].y;
					y++;
				}
				else{
					ans+=a[i].z;
					z++;
				}
			}
			else if(yy==1){
				if(a[i].x>a[i].z){
					ans+=a[i].x;
					x++;
				}
				else{
					ans+=a[i].z;
					z++;
				}
			}
			else if(zz==1){
				if(a[i].y>a[i].x){
					ans+=a[i].y;
					y++;
				}
				else{
					ans+=a[i].x;
					x++;
				}
			}
			else{
				if(a[i].y>a[i].x){
					if(a[i].y>a[i].z){
						ans+=a[i].y;
						y++;
					}
					else{
						ans+=a[i].z;
						z++;
					}
				}
				else{
					if(a[i].z>a[i].x){
						ans+=a[i].z;
						z++;
					}
					else{
						ans+=a[i].x;
						x++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
