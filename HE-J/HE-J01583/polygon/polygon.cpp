#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10000],b,o=0,ans=1,ma=-1;
	int mo=998244353;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b+=a[i];
		if(a[i]==1){
			o++;
		}
		ma=max(ma,a[i]);
	}
	if(n<=3){
		if(b>ma*2){
			printf("1");return 0;
		}
		printf("0");return 0;
	}
	if(o==n){
		printf("%d",(pow(n,n-1)+1-(2*n)));
		return 0;
	}
	printf("%d",ans%mo);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
