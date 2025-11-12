#include<bits/stdc++.h>
using namespace std;
int a[10020][10020],g2[11],f[11],ss[100021];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long sum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int s,w,g;
		scanf("%d%d%d",&s,&w,&g);
		a[s][w]=a[w][s]=g;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&g2[i]);
		for(int j=1;j<=n;j++){
			int r;
			scanf("%d",&r);
			a[j][n+i]=a[n+i][j]=r;
		}
	}
	memset(ss,0,sizeof(ss));
	int i=1;
	for(;;){
		ss[i]=1;
		int minn=1000000001,ii=-1;
		for(int j=1;j<=n+k;j++){
			if(j>n){
				if(f[j-n]==0&&a[i][j]+g2[j-n]<minn&&a[i][j]>0&&ss[j]==0){
					minn=a[i][j]+g2[j-n],ii=j;
					f[j-n]=1;
				}else if(f[j-n]==1&&a[i][j]<minn&&a[i][j]>0&&ss[j]==0){
					minn=a[i][j],ii=j;
				}
			}else if(a[i][j]<minn&&a[i][j]>1&&ss[j]==0){
				minn=a[i][j],ii=j;
			}
		}
		int f=0;
		for(int x=1;x<=n;x++){
			if(ss[x]==0){
				f=1;
				break;
			}
		}
		if(f==0) break;
		sum+=minn;
		i=ii;
		
		
	}
	printf("%lld",sum);
	return 0;
} 
