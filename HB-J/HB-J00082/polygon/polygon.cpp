#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
const int N = 5005;
const long long mod = 988244353;
int n;
long long arr[N];
long long ans;
void dfs(int x,int sum){
	if(sum > 2 * arr[x]){
		ans = (ans + 1) % mod;
	}
	if(x == n){
		return ;
	}
	for(int i = x + 1;i <= n;i++){
		dfs(i,sum + arr[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr + 1,arr + 1 + n);
	for(int i = 1;i <= n;i++){
		dfs(i,arr[i]);
	}
	printf("%lld",ans);
	return 0;
}
