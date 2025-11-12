#include<bits/stdc++.h>

using namespace std;

int n, k;
int sum;
int sum2;
int a[500005];
bool cnt[500005] = {false};

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out",  "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == k) {
            cnt[1] = true;
        }
        else {
            for(int j = i; j < n; j++) {
                sum = a[i] xor a[i + 1];
                sum2 += 2;
                for(int x = i + 3; x <= j; x++) {
                    sum = sum xor a[x];
                    sum2++;
                }
                if(sum == k) {
                    cnt[sum2] = true;
                }
                sum2 = 0;
            }
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(cnt[i] == true) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
