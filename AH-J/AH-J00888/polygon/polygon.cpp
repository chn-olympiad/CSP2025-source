#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))sum++;
	}
	else{
		for(int i=1;i<=n-2;i++){
			for(int j=n-2;j>=1;j++){
				sum+=i*j;
			}	
		}	
	}	
	printf("%d",sum);																	
	return 0;
}
