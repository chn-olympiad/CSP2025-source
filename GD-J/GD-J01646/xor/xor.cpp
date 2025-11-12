#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],maxn,NO;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		maxn=max(maxn,a[i]);
		if(a[i]==1){
			NO++;
		}
	}
	if(maxn<=1&&k==0){
		printf("%d",NO/2);
		return 0;
	}
	else if(k==1){
		printf("%d",NO);
		return 0;
	}
	
	return 0;
}
