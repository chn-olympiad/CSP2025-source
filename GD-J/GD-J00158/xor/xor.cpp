#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b; //f; // b[i] = a[0]^a[1]^...^a[i]
int n, k;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	a.resize(n+1);
	b.resize(n+1);
	// f.resize(n+1);
	
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) b[i] = b[i-1]^a[i];
	
	int last = 0;
	int s = 0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=last;j--){
			if((b[j]^b[i])==k){
				last = i;
				s++;
				break;
			}
		}
	}
	
	cout << s;
	
	// for(int i=1;i<=n;i++){
		// int t = f[i-1];
		// for(int j=i-1;j>=0;j--){
			// if((b[i]^b[j]) == k){
				// // t = max(t, f[j]+1);
				// if(f[j]+1>t){
					// t = f[j]+1;
					// break;
				// }
			// }
		// }
		// f[i] = t;
	// }
// 	
	// cout << f[n];
	// cout << endl; for(int i : b) cout << i << " ";
	// cout << endl; for(int i : f) cout << i << " ";
	return 0;
}