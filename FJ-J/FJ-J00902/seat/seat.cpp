#include<bits/stdc++.h>
using namespace std;
int n,m;
int score[105];
int spe;
bool cmp(int a,int b){
	return a>b;
}
struct node{
	int x,y;
}v[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	for(int i=1;i<=100;i++) printf("%d ",i);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&score[i]);
	spe=score[1];
	sort(score+1,score+1+n*m,cmp);
	int p=1,num=0;
	for(int i=1;i<=m;i++){
		if(p==1){
			for(int j=1;j<=n;j++){
				num++;
				v[num].x=i;
				v[num].y=j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				num++;
				v[num].x=i;
				v[num].y=j;
			}
		}
		p^=1;
	}
	for(int i=1;i<=n*m;i++){
		if(score[i]==spe){
			printf("%d %d\n",v[i].x,v[i].y);
		}
	}
	return 0;
}

