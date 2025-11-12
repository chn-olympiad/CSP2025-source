#include<stdio.h>
#include<vector>
using namespace std;
int n,k,s,a[500001],i,j,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	if(!k){
		for(i=1;i<=n;++i){
			if(!a[i])++s;
			else if(i<n&&a[i+1]==a[i])++s,++i;
		}
		printf("%d",s);
	}else{
		for(i=1;i<=n;++i)if(a[i])++s;
		printf("%d",s);
	}
	return 0;
}
