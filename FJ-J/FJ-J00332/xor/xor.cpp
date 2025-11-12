#include <iostream>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],ans = 0,h = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			for (int x = i; x <= j; x++){
				if(j - i == 0 && a[x] == k){
					ans++;
				}
				int h = 0;
				if (x == i){
					h = a[x];
				}
				else{
				h = h ^ a[x];
				}
			}
			if (h == k){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
