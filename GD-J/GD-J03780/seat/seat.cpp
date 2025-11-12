#include<bits/stdc++.h>
using namespace std;
int n,m,a,score[121],x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	score[0]=a;
    for(int i=1;i<n*m;++i){
    	scanf("%d",&score[i]);
	}sort(score,score+n*m,cmp);
	for(int j=1;j<=m;++j){
		if(j%2){
			for(int i=1;i<=n;++i){
				if(score[x++]==a){
					printf("%d %d",j,i);
				}
			}
		}else{
			for(int i=n;i>=1;--i){
				if(score[x++]==a){
					printf("%d %d",j,i);
				}
			}
		}
		
	}
	return 0;
}
