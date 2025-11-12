#include <iostream>
using namespace std;
const int N = 5e3 + 10;
int n, maxn, sum, cnt; 
int a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		sum = maxn = 0;
		for(int j = i; j <= n; j++){
			maxn = max(maxn, a[j]);
		}
		for(int j = i; j <= n; j++){
			sum += a[j];
		}
		if(maxn * 2 < sum){
			cnt++;
		}
	}
	printf("%d", cnt * 3 % 998244353);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}