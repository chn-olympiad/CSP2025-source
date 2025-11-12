#include<bits/stdc++.h>
using namespace std;
int t,n;
struct code{
	long long x,y,z;
}a[110000],p[4][110000];
int cnt[4];
long long ans,q[110000];
void fz(int x,int y){
	p[x][++cnt[x]].x=a[y].x;
	p[x][cnt[x]].y=a[y].y;
	p[x][cnt[x]].z=a[y].z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			int d=max(max(a[i].x,a[i].y),a[i].z);
			ans+=d;
			if(a[i].x==d){
				fz(1,i);
			}
			else if(a[i].y==d){
				fz(2,i);
			}
			else {
				fz(3,i);
			}
		}
		int hf=n/2;
		if(hf>=cnt[3]&&hf>=cnt[2]&&hf>=cnt[1]){
			printf("%lld\n",ans);	
			continue;
		}
		else {
			if(cnt[1]>hf){
				for(int i=1;i<=cnt[1];i++)
					q[i]=min(p[1][i].x-p[1][i].y,p[1][i].x-p[1][i].z);
				sort(q+1,q+cnt[1]+1);
				for(int i=cnt[1];i>hf;i--)
					ans-=q[i];
			}
			else if(cnt[2]>hf){
				for(int i=1;i<=cnt[2];i++)
					q[i]=min(p[2][i].y-p[2][i].x,p[2][i].y-p[2][i].z);
				sort(q+1,q+cnt[2]+1);
				for(int i=cnt[2];i>hf;i--)
					ans-=q[i];
			}
			else {
				for(int i=1;i<=cnt[3];i++)
					q[i]=min(p[3][i].z-p[3][i].y,p[3][i].z-p[3][i].x);
				sort(q+1,q+cnt[3]+1);
				for(int i=cnt[3];i>hf;i--)
					ans-=q[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
