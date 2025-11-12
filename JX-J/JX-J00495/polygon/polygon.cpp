#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+5;
int k, n;
int a[N];
int b[N];
int num = 1;
int sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
        cin >> a[i];
	}sort(a+1,a+1+n);
	b[1] = a[1] + a[2];

	for(int i = 3; i <= n; i++) {
        if(i == 3) {
            if(a[i] < b[1]) {
                sum++;
            }continue;
        }
        int k = num;
        int l = 1, r = num;
        while(l + 1 != r && l != r) {
            int mid = (l+r)/2;
            if(b[mid] > a[i]) {
                r = mid;
            }else if(b[mid] <= a[i]) {
                l = mid;
            }
        }sum += k - r + 1;
        for(int j = 1; j <= k; i++) {
            num ++;
            b[num] = b[j] + a[i];
        }
	}cout << sum;
	return 0;
}
