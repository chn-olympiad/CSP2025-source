#include<bits/stdc++.h>
using namespace std;
int x,y,z,o[4],t,n;
long long sum;
struct node{
	int x,y,dx,dy;
}a[100005];
bool cmp(node x,node y){
	return (x.x-x.y)>(y.x-y.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				a[i].x=x,a[i].dx=1;
				if(y>z) a[i].y=y,a[i].dy=2;
				else a[i].y=z,a[i].dy=3;
			}
			else if(y>=x&&y>=z){
				a[i].x=y,a[i].dx=2;
				if(x>z) a[i].y=x,a[i].dy=1;
				else a[i].y=z,a[i].dy=3;
			}
			else if(z>=x&&z>=y){
				a[i].x=z,a[i].dx=3;
				if(y>x) a[i].y=y,a[i].dy=2;
				else a[i].y=x,a[i].dy=1;
			}
		}
		sort(a+1,a+1+n,cmp);
		sum=o[1]=o[2]=o[3]=0;
		for(int i=1;i<=n;i++){
			if(o[a[i].dx]<n/2) o[a[i].dx]++,sum+=a[i].x;
			else o[a[i].dy]++,sum+=a[i].y;
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
