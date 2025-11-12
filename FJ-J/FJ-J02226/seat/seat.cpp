#include<bits/stdc++.h>
using namespace std;
struct node{
	int score,idx;
};
node b[110];
int a[20][20];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i].score);
		b[i].idx=i;
	}
	sort(b+1,b+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i].score<<" "<<b[i].idx<<endl;
//	}
	int j=1,ii=0;
	while(1){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				ii++;
				a[i][j]=b[ii].idx;
//				printf("1 %d %d %d %d\n",i,j,ii,b[ii].idx);
			}
		}else if(j%2==0){
			for(int i=n;i>=1;i--){
				ii++;
				a[i][j]=b[ii].idx;
//				printf("0 %d %d %d %d\n",i,j,ii,b[ii].idx);
			}
		}
		if(ii%n==0){
			j++;
		}
		if(ii==n*m){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				cout<<j<<" "<<i<<" "<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
