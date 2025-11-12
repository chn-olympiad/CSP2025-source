#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int x,y,z;
	int f=0;
}a[100001];
bool cmp(node a,node b){
	if(a.x==b.x){
		if(a.y==b.y) return a.z>b.z;
		else return a.y>b.y;
	}
	else return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		long long ans=0;
		int xc=0,yc=0,zc=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=n;i>=1;i--){
			if(xc>=n/2){
				int maxn=max(a[i].y,a[i].z);
				if(maxn==a[i].z){
					ans+=maxn;
					zc++;
				}
				else{
					ans+=maxn;
					yc++;
				}
			}
			else if(yc>=n/2){
				int maxn=max(a[i].x,a[i].z);
				if(maxn==a[i].z){
					ans+=maxn;
					zc++;
				}
				else{
					ans+=maxn;
					xc++;
				}
			}
			else if(zc>=n/2){
				int maxn=max(a[i].x,a[i].y);
				if(maxn==a[i].x){
					ans+=maxn;
					xc++;
				}
				else{
					ans+=maxn;
					yc++;
				}
			}
			else{
				int maxn=max(a[i].x,max(a[i].y,a[i].z));
				if(maxn==a[i].x){
					ans+=maxn;
					xc++;
				}
				else if(maxn==a[i].y){
					ans+=maxn;
					yc++;
				}
				else{
					ans+=maxn;
					zc++;
				}	
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

