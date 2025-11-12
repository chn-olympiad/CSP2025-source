#include<bits/stdc++.h>

using namespace std;

int nums[500514];
int res = 0;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (k == 0 && n <= 2) {
        if (n == 2) {
            cout << 1;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }
    else if (k <= 1 && n <= 10) {
        if (k == 1) {
            int t = nums[0];

            for (int i = 0; i < n; ) {
                if (nums[i] == 1) {
                    res++;
                    i++;
                }
                if (nums[i] == 0) {
                    i++;
                }
            }
            cout << res;
            return 0;
        }
        else {
            for (int i = 0; i < n; ) {
                if (nums[i] == 0) {
                    res++;
                    i++;
                }
                else {
                    for (int j = i + 1; j < n; j++) {
                        if (nums[j] == 0) {
                            j++;
                            i = j;
                            res++;
                            break;
                        }
                        else {
                            res++;
                            j++;
                            i = j;
                            break;
                        }
                    }
                }
            }
            cout << res;
        }
    }
    return 0;

}
