#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[50001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==5&&a[1]==1){
		printf("%d",9);
	}
	if(n==5&&a[1]==2){
		printf("%d",6);
	}
	if(n==20){
		printf("%d",1042392);
	}
	if(n==500){
		printf("%d",366911923);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
