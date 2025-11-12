#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4],d[210][210],ans,f[50010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		memset(d,0,sizeof(d));
		ans=0;
		if(n>300){
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int k=min(n/2,i);k>=0;k--){
					int p=i-k;
					if(p<0 || p>n/2) continue;
					if(p) f[k]=max(f[k],f[k]+a[i][2]);
					if(k) f[k]=max(f[k-1],f[k-1]+a[i][1]);
					if(i==n) ans=max(ans,f[k]);
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int k=min(n/2,i);k>=0;k--){
				for(int p=min(n/2,i);p>=0;p--){
					int q=i-k-p;
					if(q<0 || q>n/2) continue;
					if(q) d[k][p]=max(d[k][p],d[k][p]+a[i][3]);
					if(k) d[k][p]=max(d[k][p],d[k-1][p]+a[i][1]);
					if(p) d[k][p]=max(d[k][p],d[k][p-1]+a[i][2]);
//					printf("%d %d %d>>%d\n",k,p,q,d[k][p][q]);
					if(i==n) ans=max(ans,d[k][p]); 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
