#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;

struct node{
	int x,y,z;
}a[N+1],xton[50010],yton[50010],zton[50010];
int maxx(int x,int y,int z){
	return max(x,max(y,z));
}
bool cmpx(node x,node y){
	if(x.x==y.x)return max(x.y,x.z)<max(y.y,y.z);
	return x.x<y.x;
}
bool cmpy(node x,node y){
	if(x.y==y.y)return max(x.x,x.z)<max(y.x,y.z);
	return x.y<y.y;
}
bool cmpz(node x,node y){
	if(x.z==y.z)return max(x.y,x.x)<max(y.y,y.x);
	return x.z<y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(xton,0,sizeof(xton));
		memset(yton,0,sizeof(yton));
		memset(zton,0,sizeof(zton));
		int n;
		scanf("%d",&n);
		bool flagx=1,flagy=1,flagz=1; 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x!=0)flagx=0;
			if(a[i].y!=0)flagy=0;
			if(a[i].z!=0)flagz=0;
		}
		if(flagy&&flagz){
			sort(a+1,a+1+n,cmpx);
			ll ans=0;
			for(int i=n;i>n/2;i--)ans+=a[i].x;
			printf("%lld\n",ans);
			continue;
		}
		ll x=0,y=0,z=0;
		int xcnt=0,ycnt=0,zcnt=0;
		for(int i=1;i<=n;i++){
			if(maxx(a[i].x,a[i].y,a[i].z)==a[i].x){
				if(xcnt==n/2){
					int id=-1,cha=-1;
					for(int j=1;j<=xcnt;j++){
						if(a[i].x+max(xton[j].y,xton[j].z)>xton[j].x+max(a[i].y,a[i].z)){
							if(cha<a[i].x+max(xton[j].y,xton[j].z)-xton[j].x+max(a[i].y,a[i].z)){
								id=j;
								cha=a[i].x+max(xton[j].y,xton[j].z)-xton[j].x+max(a[i].y,a[i].z);
							}
						}
					}
					if(id!=-1){
						x-=ll(xton[id].x);
						x+=ll(a[i].x);
						if(xton[id].y>xton[id].z){
							yton[++ycnt]=xton[id];
							y+=ll(xton[id].y);
						}
						else{
							zton[++zcnt]=xton[id];
							z+=ll(xton[id].z);
						}
						xton[id]=a[i];
					}
					else{
						if(a[i].y>a[i].z){
							yton[++ycnt]=a[i];
							y+=ll(a[i].y);
						}
						else{
							zton[++zcnt]=a[i];
							z+=ll(a[i].z);
						}
					}
				}
				else{
					xton[++xcnt]=a[i];
					x+=ll(a[i].x);
				}
			}
			else if(maxx(a[i].x,a[i].y,a[i].z)==a[i].y){
				if(ycnt==n/2){
					int id=-1,cha=-1;
					for(int j=1;j<=ycnt;j++){
						if(a[i].y+max(yton[j].x,yton[j].z)>yton[j].y+max(a[i].x,a[i].z)){
							if(cha<a[i].y+max(yton[j].x,yton[j].z)-yton[j].y+max(a[i].x,a[i].z)){
								id=j;
								cha=a[i].y+max(yton[j].x,yton[j].z)-yton[j].y+max(a[i].x,a[i].z);
							}
						}
					}
					if(id!=-1){
						y-=ll(yton[id].y);
						y+=ll(a[i].y);
						if(yton[id].x>yton[id].z){
							xton[++xcnt]=yton[id];
							x+=ll(yton[id].x);
						}
						else{
							zton[++zcnt]=yton[id];
							z+=ll(yton[id].z);
						}
						yton[id]=a[i];
					}
					else{
						if(a[i].x>a[i].z){
							xton[++xcnt]=a[i];
							x+=ll(a[i].x);
						}
						else{
							zton[++zcnt]=a[i];
							z+=ll(a[i].z);
						}
					}
				}
				else{
					yton[++ycnt]=a[i];
					y+=ll(a[i].y);
				}
			}
			else if(maxx(a[i].x,a[i].y,a[i].z)==a[i].z){
				if(zcnt==n/2){
					int id=-1,cha=-1;
					for(int j=1;j<=zcnt;j++){
						if(a[i].z+max(zton[j].x,zton[j].y)>zton[j].z+max(a[i].x,a[i].y)){
							if(cha<a[i].z+max(zton[j].x,zton[j].y)-zton[j].z+max(a[i].x,a[i].y)){
								id=j;
								cha=a[i].z+max(zton[j].x,zton[j].y)-zton[j].z+max(a[i].x,a[i].y);
							}
						}
					}
					if(id!=-1){
						z-=ll(zton[id].z);
						z+=ll(a[i].z);
						if(zton[id].x>zton[id].y){
							xton[++xcnt]=zton[id];
							x+=ll(zton[id].x);
						}
						else{
							yton[++ycnt]=zton[id];
							y+=ll(zton[id].y);
						}
						zton[id]=a[i];
					}
					else{
						if(a[i].x>a[i].y){
							xton[++xcnt]=a[i];
							x+=ll(a[i].x);
						}
						else{
							yton[++ycnt]=a[i];
							y+=ll(a[i].y);
						}
					}
				}
				else{
					zton[++zcnt]=a[i];
					z+=ll(a[i].z);
				}
			}
		}
		printf("%lld\n",x+y+z);
	}
	return 0;
}
