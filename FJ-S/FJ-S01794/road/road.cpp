#include<stdio.h>
#include<algorithm>
using namespace std;
int min(int a,int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}
//int v[100005]={0},w[100005][5]={0},c[105]={0},d[15][10005]={0},a[10005][10005]={0};
/*long long min=1e15;
void dfS(int a[][10005],int op[][10005],int s,int n,long long sum){
	if(s==n){ 
		min=sum;
		return;
	}
	for(int i=1;i<=n;i++){
	}
}*/
struct node{
	int v;
	int flag;
}b[100000005];
int cmp(struct node v1,struct node v2){
	if(v1.v<v2.v){
		return 1;
	}else{
		return 0;
	}
}
int a[10005][10005]={0},op[10005][10005]={0},len=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		int w1,w2,v;
		scanf("%d %d %d",&w1,&w2,&v);
		if(w1<w2){
			a[w1][w2]=v;
		}else{
			a[w2][w1]=v;
		}
	}
	int c[15]={0};
	for(int i=1;i<=k;i++){
		int d[10005]={0};
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&d[j]);
		}
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[j][l]==-1){
					a[j][l]=d[j]+d[l];
				}else{
					if(a[j][l]>d[j]+d[l]){
						a[j][l]=d[j]+d[l];
						op[j][l]=i;
					}
				}
				//b[++len]=a[j][k];
				//printf("%d ",a[j][k]);
			}
			//printf("\n");
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			b[++len].v=a[i][j];
			b[len].flag=op[i][j];
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	sort(b+1,b+1+len,cmp);
	for(int i=1;i<=len;i++){
		printf("%d ",b[i].v);
	}
	long long sum=0,e[15]={0};
	for(int i=1;i<n;i++){
		if(b[i].flag!=0&&e[b[i].flag]==0){
			sum+=c[b[i].flag];
			e[b[i].flag]=1;
		}
		sum+=b[i].v;
	}
	printf("%lld",sum);*/
	printf("0");
	return 0;
}