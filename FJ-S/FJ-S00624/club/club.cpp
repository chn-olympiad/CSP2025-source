#include<bits/stdc++.h>
using namespace std;
struct xy{
	int x,y,z,xid,yid,zid;
}b[100010];
int t,n,a[100010][5],k,c[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
	while(t--){
		for(int i=1;i<=3;i++){
			c[i]=0;
		}
		int sum=0;
		scanf("%d",&n);
		k=n/2;
		for(int i=1;i<=n;i++){
			b[i].x=-1e9,b[i].z=1e9;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>b[i].x){
				   b[i].x=a[i][j];
				   b[i].xid=j;
				}
				if(a[i][j]<b[i].z){
				   b[i].z=a[i][j];
				   b[i].zid=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=b[i].xid&&j!=b[i].zid){
				   b[i].y=a[i][j];
				   b[i].yid=j;
				}
			}
		}
	    for(int i=1;i<n;i++){
	    	for(int j=1;j<=n-i;j++){
	    		if(b[j].x<b[j+1].x){
	    		   swap(b[j],b[j+1]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(c[b[i].xid]<k){
			   sum+=b[i].x;
			   c[b[i].xid]++;
			}
			else if(c[b[i].yid]<k){
				sum+=b[i].y;
				c[b[i].yid]++;
			}
			else if(c[b[i].zid]<k){
				sum+=b[i].z;
				c[b[i].zid]++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
