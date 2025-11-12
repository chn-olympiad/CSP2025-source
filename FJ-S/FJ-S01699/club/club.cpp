#include<bits/stdc++.h>
using namespace std;
int T,n,ans,p,t,r;
struct myclub{
	int x,y,z,w;
}a[100055];
bool cmp(myclub u,myclub v){
	return u.w>v.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0,p=0,t=0,r=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
				a[i].w=a[i].x-max(a[i].y,a[i].z);
			}
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
				a[i].w=a[i].y-max(a[i].x,a[i].z);
			}
			else{
				a[i].w=a[i].z-max(a[i].x,a[i].y);
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
				if(p<n/2){
					p++;
					ans+=a[i].x;
					continue;
				}
				if(a[i].y>=a[i].z){
					t++;
					ans+=a[i].y;
					continue;
				}
				else{
					r++;
					ans+=a[i].z;
					continue;
				}
			}
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
				if(t<n/2){
					t++;
					ans+=a[i].y;
					continue;
				}
				if(a[i].x>=a[i].z){
					p++;
					ans+=a[i].x;
					continue;
				}
				else{
					r++;
					ans+=a[i].z;
					continue;
				}
			}
			else{
				if(r<n/2){
					r++;
					ans+=a[i].z;
					continue;
				}
				if(a[i].x>=a[i].y){
					p++;
					ans+=a[i].x;
					continue;
				}
				else{
					t++;
					ans+=a[i].y;
					continue;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
