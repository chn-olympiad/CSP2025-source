#include<stdio.h>
#include<queue>
using namespace std;
struct node{
	int sum;
	int op[10];
	//int b[100000];
	int s;
}v1,v2,v3,v4;
int n,a[100005][4]={0};
int main(){
	freopen("club.in","r",stdin);
	//freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				scanf("%d",&a[j][k]);
			}
		}
		queue<struct node> b;
		for(int j=1;j<=3;j++){
			v1.sum=a[1][j];
			v1.op[j]=1;
			v1.s=2;
			//v1.b[1]=j;
			b.push(v1);
			v1.op[j]=0;
		}
		/*for(int j=1;j<=n;j++){
			v4.b[j]=0;
		}
		v4.sum=0;*/
		long long max=0;
		while(!b.empty()){
			v2=b.front();
			//printf("%d\n",v2.sum);
			if(max<v2.sum){
				max=v2.sum;
			}
			b.pop();
			for(int j=1;j<=3;j++){
				if(v2.op[j]*2<n&&v2.s<=n){
					v3=v2;
					v3.sum+=a[v2.s][j];
					v3.op[j]++;
					//v3.b[v3.s]=j;
					v3.s++;
					b.push(v3);
				}
			}
		}
		/*for(int j=1;j<=n;j++){
			printf("%d ",v4.b[j]);
		}
		printf("%d",max);
		printf("\n");*/
		printf("%lld\n",max);
	}
	return 0;
}