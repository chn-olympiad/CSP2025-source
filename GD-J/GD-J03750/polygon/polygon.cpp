#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum;
int PPow(int NNow,int MMg){
	if(NNow == 1){
		return MMg;
	}
	int ssum = 0;
	for(int i = n-NNow;i <= MMg;i++){
		ssum += PPow(NNow-1,i);
		ssum %= 998244353;
	}
	return ssum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n == 3){
		printf("1");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i++){
		sum += PPow(i,n);
		sum %= 998244353;
	}
	printf("%d",sum);
	return 0;
}
