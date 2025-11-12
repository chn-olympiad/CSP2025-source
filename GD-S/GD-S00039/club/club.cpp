#include<bits/stdc++.h>
using namespace std;
int T,n;
int p1[100005],p2[100005],p3[100005];
struct tni{
	int x,y,z;
}a[100005];
bool cmp1(int x,int y){
	return max(a[x].y,a[x].z)-a[x].x<max(a[y].y,a[y].z)-a[y].x;
}
bool cmp2(int x,int y){
	return max(a[x].x,a[x].z)-a[x].y<max(a[y].x,a[y].z)-a[y].y;
}
bool cmp3(int x,int y){
	return max(a[x].x,a[x].y)-a[x].z<max(a[y].x,a[y].y)-a[y].z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		p1[0]=0;
		p2[0]=0;
		p3[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				p1[++p1[0]]=i;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				p2[++p2[0]]=i;
			}
			else{
				p3[++p3[0]]=i;
			}
		}
		if(p1[0]>n/2){
			stable_sort(p1+1,p1+p1[0]+1,cmp1);
			for(int i=n/2+1;i<=p1[0];i++){
				int t=p1[i];
				if(a[t].y>=a[t].z) p2[++p2[0]]=t;
				else p3[++p3[0]]=t;
			}
			p1[0]=n/2;
		}
		if(p2[0]>n/2){
			stable_sort(p2+1,p2+p2[0]+1,cmp2);
			for(int i=n/2+1;i<=p2[0];i++){
				int t=p2[i];
				if(a[t].x>=a[t].z) p1[++p1[0]]=t;
				else p3[++p3[0]]=t;
			}
			p2[0]=n/2;
		}
		if(p3[0]>n/2){
			stable_sort(p3+1,p3+p3[0]+1,cmp3);
			for(int i=n/2+1;i<=p3[0];i++){
				int t=p3[i];
				if(a[t].x>=a[t].y) p1[++p1[0]]=t;
				else p2[++p2[0]]=t;
			}
			p3[0]=n/2;
		}
		int ans=0;
		for(int i=1;i<=p1[0];i++){
			int t=p1[i];
			ans+=a[t].x;
		}
		for(int i=1;i<=p2[0];i++){
			int t=p2[i];
			ans+=a[t].y;
		}
		for(int i=1;i<=p3[0];i++){
			int t=p3[i];
			ans+=a[t].z;
		}
		printf("%d\n",ans);
	}
	return 0;
}
