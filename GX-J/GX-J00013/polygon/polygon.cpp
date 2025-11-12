#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("polygon.in", "r", stdin);
//    freopen("polygon.out", "w", stdout);

    int n, arr[5005] = {}, cntM = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n-1; i++) {
        int Max = -1, cnt = 0;
        Max = max(arr[i], arr[i+1]);
        cnt = arr[i] + arr[i+1];
        for(int j = i + 2; j < n; j++) {
            cnt += arr[j];
            Max = max(Max, arr[j]);
            if(cnt > Max*2) {
                cntM++;
                cout << i+1 << ' ' << j+1 << '\t' << cnt << ' ' << Max << "\n";
            }
        }
    }
    cout << cntM;
    return 0;
}
