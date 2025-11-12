#include <bits/stdc++.h>
using namespace std;
int n,m,X,Y,CNT=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&X);
	for(int i=1;i<n*m;i++){
		scanf("%d",&Y);
		if(Y>X) CNT++;
	}
	Y=CNT/n;
	if(CNT%n==0){
		if(Y&1){
			printf("%d %d",Y,n);
		}
		else{
			printf("%d 1",Y);
		}
	}
	else{
		Y++;
		if(Y&1){
			printf("%d %d",Y,CNT%n);
		}
		else{
			printf("%d %d",Y,n-(CNT%n)+1);
		}
	}
	return 0;
}
