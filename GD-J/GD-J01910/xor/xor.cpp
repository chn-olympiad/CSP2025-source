#include<cstdio>
using namespace std;
int n,k,s[500001],js;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]==1)js++;
	}
	if(js==n&&k==0){
		if(n==1)printf("0");
		else if(n==2)printf("1");
		else printf("%d",n/2);
	}
	
	return 0;
}
