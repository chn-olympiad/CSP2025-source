#include <iostream>
#define ll long long
using namespace std;
ll n, k, a[500005], ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		int tmp = a[i];
		for(int j = i + 1;j <= n;j++){
			tmp ^= a[j];
			if(tmp == k){
				ans++;
				break;
			} 
		} 
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
