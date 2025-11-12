#include<stdio.h>
int now=0,n,k,cnt=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		now^=a;
		if(now==k){
			cnt++;
			now=0;
		}
	}printf("%d",cnt);
	return 0;
}
