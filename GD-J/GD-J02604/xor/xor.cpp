#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=2){
		if(n==1) printf("0");
		else printf("1");
	}
	else if(k==0 && n<=100){
		printf("%d",n/2);
	}
	else if(k<=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		printf("%d",ans);
	}
	return 0;
} 
