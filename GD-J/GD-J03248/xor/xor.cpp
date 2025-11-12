#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
unsigned long long arr[500005];
bool f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i<=n;i++)	scanf("%lld",&arr[i]);
	for(long long k = 1;k<=n;k++)
		for(long long i = 1;i<=n-k+1;i++){
			int ans = arr[i];
			for(long long j = i;j<=i+k-1;j++)
				ans ^ arr[j];
			if(ans == k)
				cnt++;
		}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
