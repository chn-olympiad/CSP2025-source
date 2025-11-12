#include <iostream>
using namespace std;
#define xorp(a,b) (((a) | (b)) & ~((a) & (b)))
#define MAXN 500001
unsigned int n,k,a[MAXN],f[MAXN],maxx[MAXN],xorr;//n <= 5e5
int main() {
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	f[0] = maxx[0] = 0;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		xorr = 0;
		for(int j = i;j >= 1;--j) {
            xorr = xorr xor a[j];
            if(xorr == k) {
                f[i] = max(f[i],maxx[j - 1] + 1);
            }
		}
		maxx[i] = max(maxx[i - 1],f[i]);
	}
	cout << maxx[n];
	return 0;
}

