#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, ans;
int a[500001];
bool b[500001];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if (a[i] == k){
			ans ++;
			b[i] = true;
		}
	}
	
	for (int i=1; i<=n; i++){
		if (b[i]) continue;
		int num = 0, end=i;
		for (int j=i; j<=n; j++){
			if (b[j]) break;
			num = num xor a[j];
			if (num == k){
				ans ++;
				end = j;
				break;
			}
		}
		i = end;
	}
	cout << ans;
    return 0;
}

