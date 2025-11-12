#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, k;
int a[500005];
int q[500005], b[2500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	b[0] = 1, q[1] = a[1];
	int l = 1, ans = 0;
	for(int i = 1; i <= n; i++){
		b[q[i]]++;
		bool ok = false;
		if(q[i] == (k ^ q[i])){
			if(b[q[i]] >= 2){
				ok = true;
			}
		}else{
			if(b[k ^ q[i]]){
				ok = true;
			}
		}
		q[i + 1] = q[i] ^ a[i + 1];
		if(ok){
			ans++;
			while(l <= i){
				b[q[l]]--, l++;
			}
			q[i + 1] = a[i + 1];
		}
	}
	cout << ans << endl;
	return 0;
}
