#include<bits/stdc++.h>
using namespace std;
int n,m,b[120][20];
struct st{
	int a,ls;
}q[110];
bool cmp(st x,st y){
	return x.a>y.a;
}
signed main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&q[i].a);
		q[i].ls=i;
	}
	sort(q+1,q+1+n*m,cmp);
	int v,k=0;
	for(int i=1;i<=n*m;i++){
		if(q[i].ls==1){
			v=i;
			break;
		}
	}
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=n;j++){
			b[i][j]=++k;
			if(k==v){
				printf("%d %d",i,j);
				return 0;
			}
		}
		for(int j=n;j>=1;j--){
			b[i+1][j]=++k;
			if(k==v){
				printf("%d %d",i+1,j);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
