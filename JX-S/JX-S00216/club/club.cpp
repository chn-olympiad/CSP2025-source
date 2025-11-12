#include <bits/stdc++.h>
using namespace std;

int T, n, a, b, c;
int A[100005], lena;
int B[100005], lenb;
int C[100005], lenc;
int ans;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = lena = lenb = lenc = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b >> c;
            if (a >= max(b, c)) {
                ans += a;
                A[++lena] = max(b - a, c - a);
            }
            else if (b >= max(a, c)) {
                ans += b;
                B[++lenb] = max(a - b, c - b);
            }
            else {
                ans += c;
                C[++lenc] = max(a - c, b - c);
            }
        }
        if (lena > n / 2) {
            sort(A + 1, A + lena + 1);
            for (int i = lena; i > n / 2; i--) ans += A[i];
        }
        else if (lenb > n / 2) {
            sort(B + 1, B + lenb + 1);
            for (int i = lenb; i > n / 2; i--) ans += B[i];
        }
        else if (lenc > n / 2) {
            sort(C + 1, C + lenc + 1);
            for (int i = lenc; i > n / 2; i--) ans += C[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
