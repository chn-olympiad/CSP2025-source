#include <bits/stdc++.h>
using namespace std;
int t, n, x, ans, a[100005][3];
priority_queue<int> q1;
priority_queue<int> q2;
priority_queue<int> q3;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int k = 1;k <= t;k++){
        ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i++){
            cin >> x;
            q1.push(x);
            cin >> x;
            q2.push(x);
            cin >> x;
            q3.push(x);
        }
        while (!(q1.size()+q2.size()+q3.size())){
            cout << q1.size()+q2.size()+q3.size();
            ans += max(q1.top(), max(q2.top(), q3.top()));
            if (q1.top() > q2.top()){
                if (q1.top() > q3.top()) q1.pop();
                else{
                    if (q2.top() > q3.top()) q2.pop();
                    else q3.pop();
            }
            }
        }
        cout << ans << endl;
    }
    return 0;
}