#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, t;
queue<int> a, b, c;
int ans;

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        int maxn = n / 2;
        for(int i = 1; i <= n; i++){
            int A, B, C;
            cin >> A >> B >> C;
            if(A > B && A > C)
                a.push(A);
            else if(B > A && B > C)
                b.push(B);
            else
                c.push(C);
            if(a.size() > maxn){
                a.pop();
                if(B > C)
                    b.push(B);
                else
                    c.push(C);
            }
            else if(b.size() > maxn){
                b.pop();
                if(A > C)
                    a.push(A);
                else
                    c.push(C);
            }
            else if(c.size() > maxn){
                c.pop();
                if(A > B)
                    a.push(A);
                else
                    b.push(B);
            }
        }
        while(!a.empty()) ans += a.front(), a.pop();
        while(!b.empty()) ans += b.front(), b.pop();
        while(!c.empty()) ans += c.front(), c.pop();
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
