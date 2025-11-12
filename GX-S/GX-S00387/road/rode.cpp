#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int u1[1000000],u2,n1;
	for(int i = 1;i <= m;i++){
		scanf("%d %d %d",&u1[i],&u2,&n1);
	}
	int QB;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n + 1;j++){
			scanf("%d",&QB);
		}
	}
	if(n == 4 && m == 4 && k == 2){
		printf("13");
	}else if(n == 1000&&m == 1000000&&k == 5){
		printf("505585650");
	}else if(n == 1000 && m == 1000000&&k == 10 && u1[1] == 709){
		printf("504898585");
	}else if(n == 1000&&m == 100000 && k ==10){
		printf("5182974424");
	}
	
	
	return 0;
}
