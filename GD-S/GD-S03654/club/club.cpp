#include<bits/stdc++.h>
using namespace std;
int a[100001][3],c[100001],p[100001],k[100001];
int q[100001];
int mx(int x,int y){
	if(x<y) return y;
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,s=0;
		scanf("%d",&n);
		k[0]=0,k[1]=0,k[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int ma=mx(mx(a[i][0],a[i][1]),a[i][2]);
			if(ma==a[i][0]) k[0]++,s+=a[i][0],c[i]=0,p[i]=mx(a[i][1],a[i][2]);
			else if(ma==a[i][1]) k[1]++,s+=a[i][1],c[i]=1,p[i]=mx(a[i][0],a[i][2]);
			else if(ma==a[i][2]) k[2]++,s+=a[i][2],c[i]=2,p[i]=mx(a[i][0],a[i][1]); 
		}
		int f=-1;
		for(int i=0;i<3;i++) if(k[i]>n/2) f=i;
		if(f!=-1){
			int l=0;
			for(int i=1;i<=n;i++){
				if(c[i]!=f) continue;
				q[++l]=a[i][c[i]]-p[i];
			}
			sort(q+1,q+1+l);
			for(int i=1;i<=k[f]-n/2;i++) s-=q[i];
		}
		printf("%d\n",s);
	}
	
	return 0;
} 
