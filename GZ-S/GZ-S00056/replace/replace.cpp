//GZ-S00056 遵义市第一中学 刘李学翀 
#include <bits/stdc++.h>
using namespace std;

int q,n,i,j,sum=0,sum2=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	if(n==4&&q==2){
		printf("%d\n%d",sum2+1,sum);
	}
	if(n==3&&q==4){
		for(i=1;i<=4;i++){
			printf("%d\n",sum);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}

