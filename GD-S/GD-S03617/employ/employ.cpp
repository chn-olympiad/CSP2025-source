#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a = 0,b = 0;
	long long ans = 1;
	char ch;
	scanf("%d%d" ,&n,&m);
	for(int i = 1;i <= n;i++){
		scanf(" %c" ,&ch);
		if((ch - '0') == 0){
			a = 1;
		}else{
			b = 1;
		}
	}
	if((a == 1 && m == n) || b == 0){
		printf("0");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		ans *= i;
		ans %= 998244353;
	}
	printf("%lld" ,ans);
	return 0;
}
