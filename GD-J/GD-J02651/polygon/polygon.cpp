#include <iostream>
#include <cstdio>
const int mod=998244353; 
using namespace std;

int n,num[5500],sum;

void dfs(int a,int b,int c){
	if(a==n+1){
		if(b>c*2)sum=(sum+1)%mod;
		return;
	}
	dfs(a+1,b+num[a],max(c,num[a]));
	dfs(a+1,b,c);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",num+i);
	if(n<=23){
		dfs(1,0,0);
		printf("%d\n",sum);
	}else printf("0\n");
	return 0;
}
