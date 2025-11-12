#include<bits/stdc++.h>
using namespace std;
int n;
struct dmh{
	int x1;
	int x2;
	int x3;
	long long book;
	int nn;
}a[1000005];
int y11,y2,y3;
long long c[200005];
long long num,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
while(t--){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
		if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3){
			y11++;
			num+=a[i].x1;
			a[i].book=a[i].x1-max(a[i].x2,a[i].x3);
			a[i].nn=1;
		}
		else if(a[i].x2>=a[i].x1&&a[i].x2>=a[i].x3){
			y2++;
			num+=a[i].x2;
			a[i].book=a[i].x2-max(a[i].x1,a[i].x3);
			a[i].nn=2;
		}
		else if(a[i].x3>a[i].x1&&a[i].x3>a[i].x1){
			y3++;
			num+=a[i].x3;
			a[i].book=a[i].x3-max(a[i].x1,a[i].x2);
			a[i].nn=3;
		}
	}
	if(y11>n/2){
		int w=0,yy=y11-n/2;
		for(int i=1;i<=n;i++){
			if(a[i].nn==1){
				c[++w]=a[i].book;
			}
		}
		sort(c+1,c+1+w);
		for(int i=1;i<=yy;i++){
			num-=c[i];
		}
	}
	if(y2>n/2){
		int w=0,yy=y2-n/2;
		for(int i=1;i<=n;i++){
			if(a[i].nn==2){
				c[++w]=a[i].book;
			}
		}
		sort(c+1,c+1+w);
		for(int i=1;i<=yy;i++){
			num-=c[i];
		}
	}
	if(y3>n/2){
		int w=0,yy=y3-n/2;
		for(int i=1;i<=n;i++){
			if(a[i].nn==3){
				c[++w]=a[i].book;
			}
		}
		sort(c+1,c+1+w);
		for(int i=1;i<=yy;i++){
			num-=c[i];
		}
	}
	printf("%lld\n",num);
	num=0;
	y11=y2=y3=0;
	sum=0;
}
	return 0;
}
