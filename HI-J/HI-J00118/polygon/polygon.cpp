#include<bits/stdc++.h>
usong namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
