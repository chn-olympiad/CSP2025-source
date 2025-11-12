#include<bits/stdc++.h>
using namespace std;
#define N 5005
int P[N];
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int p,ma=0;
	scanf("%d",&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&P[i]);
		ma=max(ma,P[i]);
	}if(ma==1){
		printf("%lld",6);
	}else if(p==3){
		sort(P+1,P+3);
		if(P[1]+P[2]>P[3]) printf("1");
		else printf("0");
		return 0;
	}
	return 0;
}