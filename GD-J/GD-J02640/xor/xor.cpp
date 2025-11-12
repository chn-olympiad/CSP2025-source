#include <fstream>
#include <vector>
using namespace std;
ifstream cin("xor.in");
ofstream cout("xor.out");
int n, k, txor[500001], dp[500001];
vector<int> v[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> txor[i];
		txor[i] ^= txor[i - 1];
	}
	for(int j=1; j<=n; j++)
		for(int i=j-1; i>=0; i--)
			if((txor[j] ^ txor[i]) == k)
				{v[j].push_back(i); break;}
	for(int i=1; i<=n; i++){
		dp[i] = dp[i - 1];
		for(int j : v[i])
			dp[i] = max(dp[i], dp[j] + 1);
	}
	cout << dp[n];
	return 0;
}
