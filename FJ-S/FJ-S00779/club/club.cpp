#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
node a[100010];
int t,n;
int sx,sy,sz;
int xx[100010],yy[100010],zz[100010];
bool fx,fy,fz;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		sx=0,sy=0,sz=0;
		fx=0,fy=0,fz=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			xx[i]=a[i].x;
			yy[i]=a[i].y;
			zz[i]=a[i].z;
		}
		for (int i=1;i<=n;i++){
			if (a[i].y==0&&a[i].z==0) fx=1;
			else{
				fx=0;
				break;	
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i].x==0&&a[i].z==0) fy=1;
			else{
				fy=0;
				break;	
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i].x==0&&a[i].y==0) fz=1;
			else{
				fz=0;
				break;	
			}
		}
		sort(xx+1,xx+n+1,cmp);
		for (int i=1;i<=n/2;i++) sx+=xx[i];
		sort(yy+1,yy+n+1,cmp);
		for (int i=1;i<=n/2;i++) sy+=yy[i];
		sort(zz+1,zz+n+1,cmp);
		for (int i=1;i<=n/2;i++) sz+=zz[i];
		if (fx==1) printf("%d\n",sx);
		else if (fy==1) printf("%d\n",sy);
		else if (fz==1) printf("%d\n",sz);
		else printf("%d\n",int(ceil(1.99*max(max(sx,sy),sz))));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
