#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, k;
int t[N][30];
int res = 0;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        for(int j = 0;j <= 20;j++) {
            t[i][j] = t[i - 1][j];
        }
        for(int j = 0;(1 << j) <= x;j++) {
            if((x >> j) & 1)t[i][j]++;
        }
    }
    int r;
    int x;
    for(int l = 1;l <= n;l++) {
        r = l;
        while(r <= n) {
            int flag = 1;
            for(int i = 0;i <= 20;i++) {
                x = t[r][i] - t[l - 1][i];
                if(((k >> i) & 1) && x % 2 == 0) {
                    flag = 0;
                    break;
                }
                else if((k >> i) % 2 == 0 && x % 2 == 1) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                l = r;
                res++;
                break;
            }
            r++;
        }
    }
    cout << res;
    return 0;
}
