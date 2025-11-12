#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,r;
}a[100005];
bool cmp4(node n,node m){return abs(n.x-n.y)>abs(m.x-m.y);}
bool cmp5(node n,node m){return n.x>m.x;}
int n,t,p,q,m,ans,ff=1,f=1;
void bl(int aa,int bb,int cc,int dd){
	ans=max(ans,a[aa].x+a[bb].x+a[cc].y+a[dd].y);
	ans=max(ans,a[aa].x+a[bb].x+a[cc].y+a[dd].z);
	ans=max(ans,a[aa].x+a[bb].x+a[cc].z+a[dd].z);
	ans=max(ans,a[aa].x+a[bb].y+a[cc].y+a[dd].z);
	ans=max(ans,a[aa].y+a[bb].y+a[cc].z+a[dd].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y) ff=0;
			if(a[i].z) ff=f=0;
		}
		if(n==2){
			ans=max(ans,a[1].x+a[2].y);
			ans=max(ans,a[1].y+a[2].z);
			ans=max(ans,a[1].x+a[2].z);
			ans=max(ans,a[2].x+a[1].y);
			ans=max(ans,a[2].y+a[1].z);
			ans=max(ans,a[2].x+a[1].z);
			printf("%d\n",ans);
		}
		else if(n==4){
			bl(1,2,3,4);
			bl(1,2,4,3);
			bl(1,3,2,4);
			bl(1,3,4,2);
			bl(1,4,3,2);
			bl(1,4,2,3);
			bl(2,1,3,4);
			bl(2,1,4,3);
			bl(2,3,1,4);
			bl(2,3,4,1);
			bl(2,4,1,3);
			bl(2,4,3,1);
			bl(3,1,2,4);
			bl(3,1,4,2);
			bl(3,2,1,4);
			bl(3,2,4,1);
			bl(3,4,1,2);
			bl(3,4,2,1);
			bl(4,1,2,3);
			bl(4,1,3,2);
			bl(4,2,1,3);
			bl(4,2,3,1);
			bl(4,3,1,2);
			bl(4,3,2,1);
			printf("%d\n",ans);
		}
		else if(ff==1){
			sort(a+1,a+n+1,cmp5);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			printf("%d\n",ans);
		}
		else{
			sort(a+1,a+n+1,cmp4);
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y){
					if(p<=n/2){
						p++;
						ans+=a[i].x;
					}
					else{
						q++;
						ans+=a[i].y;
					}
				}
				if(a[i].x<a[i].y){
					if(q<=n/2){
						q++;
						ans+=a[i].y;
					}
					else{
						p++;
						ans+=a[i].x;
					}
				}
			}
			printf("%d\n",ans);
		}
		ans=0;
	}
	return 0;
}
