#include<bits/stdc++.h>
using namespace std;
int n,ans=0,ma=0,c=0;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
		ans+=a[i];
	}
	if(ans>ma*2){
		c++;
	}
	printf("%d",c);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 