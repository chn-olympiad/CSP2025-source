#include<bits/stdc++.h>
#define N 10050
#define M 50
//#define int long long
using namespace std;
int n,m,k,U,V,tw,flag,minn=0x3f3f3f;
int w[N][N],c[N],a[N][M],cw[N];
bool u[M],v[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(w,-1,sizeof(w));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&U,&V,&tw);
		w[U][V]=w[V][U]=tw;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)flag++;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(flag==k){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){w[i][j]=0;continue;}
			if(w[i][j]==-1){
				for(int h=1;h<=k;h++){
					if(!v[i])cw[h]+=a[h][i];
					if(!v[j])cw[h]+=a[h][j];
//					printf("  cw[%d] -> %d , %d += %d and %d\n",h,i,j,a[h][j],a[h][i]);
				}
				w[i][j]=0;
				v[i]=v[j]=1;
			}
			else{
				for(int h=1;h<=k;h++){
					int sum=0;
					if(!v[i])sum+=a[h][i];
					if(!v[j])sum+=a[h][j];
//					printf("cw[%d] -> %d , %d += %d or %d\n",h,i,j,sum,w[i][j]);
					cw[h]+=min(sum,w[i][j]);
				}
				v[i]=v[j]=1;
			}
		}
	}
	for(int i=1;i<=k;i++){
		minn=min(minn,cw[i]+c[i]);
	}
	printf("%d",minn);
	return 0;
}
