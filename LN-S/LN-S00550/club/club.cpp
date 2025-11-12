#include<bits/stdc++.h>
using namespace std;
struct node{
	int x1,x2,x3,maxn;
	int f;
};
bool cmp1(node x,node y){
	if(x.x1!=x.maxn){
		x.f=0x3f3f3f3f;
	}
	if(y.x1!=y.maxn){
		y.f=0x3f3f3f3f-1;
	}
	return x.f<y.f;
}
bool cmp2(node x,node y){
	if(x.x2!=x.maxn){
		x.f=0x3f3f3f3f;
	}
	if(y.x2!=y.maxn){
		y.f=0x3f3f3f3f-1;
	}
	return x.f<y.f;
}
bool cmp3(node x,node y){
	if(x.x3!=x.maxn){
		x.f=0x3f3f3f3f;
	}
	if(y.x3!=y.maxn){
		y.f=0x3f3f3f3f-1;
	}
	return x.f<y.f;
}
int n,t;
node a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int d1=0,d2=0,d3=0;
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
			if(a[i].x1==max(max(a[i].x1,a[i].x2),a[i].x3)){
				a[i].maxn=a[i].x1;
				if(a[i].x2==max(a[i].x2,a[i].x3)) a[i].f=a[i].x1-a[i].x2;
				if(a[i].x3==max(a[i].x2,a[i].x3)) a[i].f=a[i].x1-a[i].x3;
				d1+=a[i].x1;
				s1++;
			}
			if(a[i].x2==max(max(a[i].x1,a[i].x2),a[i].x3)){
				a[i].maxn=a[i].x2;
				if(a[i].x1==max(a[i].x1,a[i].x3)) a[i].f=a[i].x2-a[i].x1;
				if(a[i].x3==max(a[i].x1,a[i].x3)) a[i].f=a[i].x2-a[i].x3;
				d2+=a[i].x2;
				s2++;
			}
			if(a[i].x3==max(max(a[i].x1,a[i].x2),a[i].x3)){
				a[i].maxn=a[i].x3;
				if(a[i].x2==max(a[i].x2,a[i].x1)) a[i].f=a[i].x3-a[i].x2;
				if(a[i].x1==max(a[i].x2,a[i].x1)) a[i].f=a[i].x3-a[i].x1;
				d3+=a[i].x3;
				s3++;
			}
		}
		int ans=d1+d2+d3;
		int w=0;
		if(s1>n/2){
			w=s1-n/2;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=w;i++){
				ans-=a[i].f;
			}
		}
		if(s2>n/2){
			w=s2-n/2;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=w;i++){
				ans-=a[i].f;
			}
		}
		if(s3>n/2){
			w=s3-n/2;
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=w;i++){
				ans-=a[i].f;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
