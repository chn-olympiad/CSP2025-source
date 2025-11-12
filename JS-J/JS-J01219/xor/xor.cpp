#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5 * 1e5 +5;
int n,k,axor,in=1,a[MAXN],dp[MAXN];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		axor = axor^a[i];
		if(a[i] == k){
			dp[i] ++;
			axor = 0;
			in = i;
		}
		else if(axor == k){
			dp[i]++;
			axor = 0;
			in = i;
		}
		else{
			int inxor=0,inn = in;
			for(int j = i; j>inn; j--){
				inxor = inxor ^ a[j];
				if(inxor == k){
					inxor = 0;
					axor = 0;
					dp[i]++;
					in = i;
				}
			}
		}
	}
	cout << dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
