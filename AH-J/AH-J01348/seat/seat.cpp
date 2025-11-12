#include<bits/stdc++.h>
using namespace std;
int N,M,A[110];
int f[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N*M;i++){
		scanf("%d",&A[i]);
		f[i]=A[i];
	}
	sort(f+1,f+1+N*M,cmp);
	int id;
	for(int i=1;i<=N*M;i++)
		if(f[i]==A[1]){
			id=i;
			break;
		}
	int x=1,y=0,flag=0;
	while(id){
		id--;
		if(!flag) y++;
		else y--;
		if(y==0||y==N+1){
			x++;
			if(y==0){
				flag=0;
				y=1;
			}
			else{
				flag=1;
				y=N;
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
