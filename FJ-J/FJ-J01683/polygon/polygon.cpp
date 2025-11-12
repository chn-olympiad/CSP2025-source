#include <cstdio>
#include <algorithm>
using namespace std;
#define MOD 998244353

int n, a[5005], maxai=-1, ans, tmp=1;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		if(a[i] > maxai){
			maxai=a[i];
		}
	}
	sort(a+1, a+n+1);
	
	if(n <= 3){
		if(a[1]+a[2] > a[3]){
			printf("1");
		}
		
		return 0;
	}
	else if(maxai <= 1){
		ans+=tmp;
		for(int i=n;i>3;i--){
			tmp*=i;
			tmp%=MOD;
			ans+=tmp;
			ans%=MOD;
		}
		printf("%d", ans);
		
		return 0;
	}
	else{
		printf("%d", (n*n%MOD)*n%MOD);
	}
	return 0;
}

//Œ“À’∆≠∑÷¥¸ ¨abcdefghhhxixixi 
