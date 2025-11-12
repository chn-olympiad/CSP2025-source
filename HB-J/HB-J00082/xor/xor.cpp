#include <iostream>
#include <fstream>
using namespace std;
const int N = 5e5 + 5;
long long arr[N],dp[N],vis[N];
long long n,k;
long long sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&arr[i]);
		arr[i] ^= arr[i - 1];
	}
	int ll = 0,lr = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j >= 1;j--){
			if(j >= ll && j <= lr){
				break;
			}
			if((arr[i] ^ arr[j - 1]) == k){
				sum++;
				ll = j;
				lr = i;
				break;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
