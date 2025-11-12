#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int ii=1; ii<=t; ii++){
		int x=0,y=0,z=0;
		int n,b[114514][4],a[114514][4];
		scanf("%d%d",&n);
		for(int i=1; i<=n; i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1; i<=n; i++){
			if(x<n/2 && a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))) x++,b[x][1]=a[i][1];
			if(y<n/2 && a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))) y++,b[y][2]=a[i][2];
			if(z<n/2 && a[i][3]==max(a[i][1],max(a[i][2],a[i][3]))) z++,b[z][3]=a[i][3];
			if(x>=n/2 && a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				int ymim=a[i][1]-a[i][2],zmim=a[i][1]-a[i][3],yy,zz;//a[顺序排的人][对第几个部门]的看法； 
				for(int s=1; s<=x; s++){
					if(b[s][1]-b[s][2]<ymim) ymim=b[s][1]-b[s][2],yy=s;//b[第几个人][对第几个部门][1：满意度，2：原位置]
					if(b[s][1]-b[s][3]<zmim) zmim=b[s][1]-b[s][3],zz=s;
				}
				if((ymim<zmim && y<=n/2) || (ymim>zmim && z>=n/2) || (ymim==zmim && y<z)){
					y++,b[x+1][1]==a[i][1],b[y][2]=b[yy][1]-ymim,b[yy][1]==0;
					for(int s=yy; s<x; s++) b[s][1]=b[s+1][1];
				}
				else{
					z++,b[x+1][1]==a[i][1],b[z][3]=b[zz][1]-zmim,b[zz][1]==0;
					for(int s=zz; s<x; s++) b[s][1]=b[s+1][1];
				}
			}
			if(y>=n/2 && a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				int xmim=a[i][2]-a[i][1],zmim=a[i][2]-a[i][3],xx,zz;//a[顺序排的人][对第几个部门]的看法； 
				for(int s=1; s<=y; s++){
					if(b[s][2]-b[s][1]<xmim) xmim=b[s][2]-b[s][1],xx=s;
					if(b[s][2]-b[s][3]<zmim) zmim=b[s][2]-b[s][3],zz=s;
				}
				if((xmim<zmim && x<=n/2) || (xmim>zmim && z>=n/2) || (xmim==zmim && x<z)){
					x++,b[y+1][2]==a[i][2],b[x][2]=b[xx][1]-xmim,b[xx][2]==0;
					for(int s=xx; s<y; s++) b[s][2]=b[s+1][2];
				}
				else{
					z++,b[y+1][2]==a[i][2],b[z][3]=b[zz][1]-zmim,b[zz][2]==0;
					for(int s=zz; s<y; s++) b[s][2]=b[s+1][2];
				}
			}
			if(z>=n/2 && a[i][3]==max(a[i][1],max(a[i][2],a[i][3]))){
				int xmim=a[i][3]-a[i][1],ymim=a[i][3]-a[i][2],xx,yy;//a[顺序排的人][对第几个部门]的看法； 
				for(int s=1; s<=z; s++){
					if(b[s][3]-b[s][1]<xmim) xmim=b[s][3]-b[s][1],xx=s;//b[第几个人][对第几个部门][1：满意度，2：原位置]
					if(b[s][3]-b[s][2]<ymim) ymim=b[s][3]-b[s][2],yy=s;
				}
				if((xmim<ymim && x<=n/2) || (xmim>ymim && y>=n/2) || (xmim==ymim && x<y)){//y->x,z->y,x->y
					x++,b[z+1][3]==a[i][3],b[x][3]=b[xx][1]-xmim,b[xx][3]==0;
					for(int s=xx; s<z; s++) b[s][3]=b[s+1][3];
				}
				else{
					y++,b[z+1][3]==a[i][3],b[y][3]=b[yy][2]-ymim,b[yy][3]==0;
					for(int s=yy; s<z; s++) b[s][3]=b[s+1][3];
				}
			}
			int num=0;
			for(int s=1; s<=x; s++) num+=b[s][1];
			for(int s=1; s<=x; s++) num+=b[s][2];
			for(int s=1; s<=x; s++) num+=b[s][3];
			printf("%d/n",num);
		}
	}
	return 0;
}
