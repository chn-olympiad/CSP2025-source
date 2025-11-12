#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int T, n, A[MAXN], B[MAXN], C[MAXN];
struct Node
{
    int pos, id, num;
} f[MAXN];
bool Cmp(Node x, Node y) { return x.num < y.num; }
int main()
{
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T --)
    {
        cin >> n; for(int i = 1; i <= n; i ++) cin >> A[i] >> B[i] >> C[i];
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            ans += max(A[i], max(B[i], C[i])); f[i].pos = i;
            if(A[i] >= B[i] && A[i] >= C[i]) { cnt1 ++; f[i].num = A[i] - max(B[i], C[i]); f[i].id = 1; }
            else if(B[i] >= A[i] && B[i] >= C[i]) { cnt2 ++; f[i].num = B[i] - max(A[i], C[i]); f[i].id = 2; }
            else if(C[i] >= A[i] && C[i] >= A[i]) { cnt3 ++; f[i].num = C[i] - max(A[i], B[i]); f[i].id = 3; }
        }
        sort(f + 1, f + n + 1, Cmp);
        if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) { cout << ans << '\n'; continue; }
        int dd = 0;
        if(cnt1 > n / 2) dd = 1;
        else if(cnt2 > n / 2) dd = 2;
        else dd = 3;
        for(int i = 1; i <= n; i ++)
        {
            if(f[i].id != dd) continue;
            if(dd == 1) cnt1 --;
            else if(dd == 2) cnt2 --;
            else cnt3 --;
            ans -= f[i].num;
            if(dd == 1 && cnt1 <= n / 2) break;
            if(dd == 2 && cnt2 <= n / 2) break;
            if(dd == 3 && cnt3 <= n / 2) break;
        }
        cout << ans << '\n';
    }
    return 0;
}
