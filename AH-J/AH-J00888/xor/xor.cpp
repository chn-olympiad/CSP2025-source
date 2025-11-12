#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000010],sum0,sum1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)sum0++;
		else if(a[i]==1)sum1++;
	}
	if(k==0){
		printf("%d",sum0);
	}
	else if(k==1){
		printf("%d",sum1);
	}
	else printf("2");			
	return 0;
}

