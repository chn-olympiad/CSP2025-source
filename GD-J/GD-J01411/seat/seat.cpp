#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m;
int score[MAXN*MAXN];
int seat;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&score[i]);
	}
	int sc=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sc==score[i]){
			seat=i;
			break;
		}
	}
	int line=ceil(seat*1.0/n);
	if(line%2==1){
		int siz=seat%m;
		if(siz==0){
			printf("%d %d",line,m);
		}else{
			printf("%d %d",line,siz);
		}
	}else{
		int siz=seat%m;
		if(siz==0){
			printf("%d 1",line);
		}else{
			printf("%d %d",line,m-siz+1); 
		} 
	}
	return 0;
} 
