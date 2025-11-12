#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int x;
	int y;
	int z;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s;
	cin>>s;
	while(s--){
		int n,m=0;
		cin>>n;
		aaa a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].z>a[j].z){
					int x1=a[i].x;
					a[i].x=a[j].x;
					a[j].x=x1;
					int y1=a[i].y;
					a[i].y=a[j].y;
					a[j].y=y1;
					int z1=a[i].z;
					a[i].z=a[j].z;
					a[j].z=z1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].y>a[j].y){
					int x1=a[i].x;
					a[i].x=a[j].x;
					a[j].x=x1;
					int y1=a[i].y;
					a[i].y=a[j].y;
					a[j].y=y1;
					int z1=a[i].z;
					a[i].z=a[j].z;
					a[j].z=z1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].x>a[j].x){
					int x1=a[i].x;
					a[i].x=a[j].x;
					a[j].x=x1;
					int y1=a[i].y;
					a[i].y=a[j].y;
					a[j].y=y1;
					int z1=a[i].z;
					a[i].z=a[j].z;
					a[j].z=z1;
				}
			}
		}
		//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
		int xx[n/2+1],yy[n/2+1],zz[n/2+1];
		int x1=0,y1=0,z1=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y){
				if(a[i].x>=a[i].z){
					if(x1<n/2){
						m=a[i].x+m;
						xx[x1]=a[i].x;
						x1++;
						continue;
					}
					else{
						if(a[i].x>xx[1]){
						m=a[i].x+m-xx[1];
						xx[1]=a[i].x;
						sort(xx,xx+n);
						continue;
					}
					}
				}
				else{
					if(z1<n/2){
						m=a[i].z+m;
						zz[z1]=a[i].z;
						z1++;
						continue;
					}
					else if(a[i].z>zz[1]){
						m=a[i].z+m-zz[1];
						zz[1]=a[i].x;
						sort(zz,zz+n);
						continue;
					}
				}
			}
			//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
			else if(a[i].y>=a[i].x){
				if(a[i].y>=a[i].z){
					if(y1<n/2){
						m=a[i].y+m;
						yy[y1]=a[i].y;
						y1++;
						continue;
					}
					else if(a[i].y>yy[1]){
						m=a[i].y+m-yy[1];
						yy[y1]=a[i].y;
						sort(yy,yy+n);
						continue;
					}
				}
				else{
					if(z1<n/2){
						m=a[i].z+m;
						zz[z1]=a[i].z;
						z1++;
						continue;
					}
					else if(a[i].z>zz[1]){
						m=a[i].z+m-zz[1];
						zz[1]=a[i].x;
						sort(zz,zz+n);
					}
				}
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
