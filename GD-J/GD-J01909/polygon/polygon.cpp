#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}sort(a+1,a+n+1);
	if(n == 3 && a[n] * 2 < sum){
		printf("1");
	}else{
		printf("0");
	}return 0;
}
