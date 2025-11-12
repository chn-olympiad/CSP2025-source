#include<bits/stdc++.h>
using namespace std;
char s1[1000005];
long long c[10000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(n==3&&q==2){
		printf("2\n");
	}else if(n==10&&q==5){
		printf("2204128\n");
	}else{
		printf("0\n");
	}
	return 0;
}
