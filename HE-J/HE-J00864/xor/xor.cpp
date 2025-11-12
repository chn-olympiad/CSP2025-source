#include <iostream>

using namespace std;

const int N = 5e5 + 10;	

long long n,k;

long long a[N];

long long s[N];

int vis[N];

long long cnt;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	
	for (int i = 1 ; i <= n ; i ++) cin >> a[i];
	
	s[1] = a[1];
	for (int i = 2 ; i <= n ; i ++) {
		s[i] = s[i-1] ^ a[i];
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = i ; j <= n ; j ++) {
			if (s[j] ^ s[i] == k && vis[j] == 0 && vis[i] == 0) {
				cnt++;
				for (int k = i ; k <= j ; k ++) vis[k] = 1;
			}
		}
	}
	cout << cnt-1;
	return 0;
}

//4 2
//2 1 0 3

//4 3
//2 1 0 3

//4 0
//2 1 0 3
