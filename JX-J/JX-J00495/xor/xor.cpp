#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n,m,k;
int a[N],b[N];
int l = 0,sum = 0;
int cmp(int x, int y) {
	return x > y;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == k) {
            l = i;
            sum++;
        }else {
            int h = a[i];
            for(int j = i-1; j > l; j --) {
                h ^= a[j];
                if(h == k) {
                    sum ++;
                    l = i;
                    break;
                }
            }
        }
    }cout << sum;
    return 0;
}
