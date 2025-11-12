#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])printf("1");
		else printf("0");
	}
	return 0;
} 
