#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int ans;
struct data1{
	int i,a,b,c,ma,x;
}a[100005];
bool vis[100005];
bool cma(data1 x,data1 y){
	return x.a>y.a;
}
bool cmx(data1 x,data1 y){
	return x.x<y.x;
}
int xba=1,xbb=1,xbc=1,sum=0;
int suma=0,sumb=0,sumc=0;
void dfs(int x,int aa,int bb,int cc,int y){
	if(x>=n){
		ans=max(ans,y);
		return ;
	}
	if(aa+1<=n/2)dfs(x+1,aa+1,bb,cc,y+a[x+1].a);
	if(bb+1<=n/2)dfs(x+1,aa,bb+1,cc,y+a[x+1].b);
	if(cc+1<=n/2)dfs(x+1,aa,bb,cc+1,y+a[x+1].c); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=n/2;
		ans=0;
		int bja=0,bjb=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b!=0||a[i].c!=0)bja=1;
			if(a[i].c!=0)bjb=1;
		}
		if(bja==0){
			sort(a+1,a+1+n,cma);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			printf("%d\n",ans);
		}else if(bjb==0){
			for(int i=1;i<=n;i++){
				a[i].x=(a[i].a-a[i].b);
			}
			sort(a+1,a+1+n,cmx);
			for(int i=1;i<=n;i++){
				ans+=a[i].a;
			}
			for(int i=1;i<=n/2;i++){
				ans-=a[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				if(a[i].x<0)ans-=a[i].x;
			}
			printf("%d\n",ans);
		}else if(n<=10){
			ans=0;
			dfs(0,0,0,0,0);
			printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;i++){
				a[i].x=(a[i].a-a[i].b);
				a[i].i=2;
				if(a[i].x>a[i].a-a[i].c){
					a[i].x=a[i].a-a[i].c;
					a[i].i=3;
				}
			}
			sort(a+1,a+1+n,cmx);
			int xbb=0,xbc=0;
			for(int i=1;i<=n;i++){
				ans+=a[i].a;
			}
			for(int i=1;i<=n/2;i++){
				ans-=a[i].x;
				if(a[i].i==2){
					xbb++;
				}
				else{
					xbc++;
				}
			}
			for(int i=n/2+1;i<=n;i++){
				int t=0;
				if(a[i].i==2&&xbb+1<=n/2)t=1;
				if(a[i].i==3&&xbc+1<=n/2)t=1;
				if(a[i].x<0&&t==1){
					ans-=a[i].x;
				}else if(a[i].i==2){
					if(a[i].a-a[i].c<0&&xbc+1<=n/2){
						ans-=(a[i].a-a[i].c);
						xbc++;
					}
				}else if(a[i].i==3){
					if(a[i].a-a[i].b<0&&xbb+1<=n/2){
						ans-=(a[i].a-a[i].b);
						xbb++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
