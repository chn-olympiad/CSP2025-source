#include <bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005], n;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    for (int TT = 0; TT < T; TT++){
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a1[i] >> a2[i] >> a3[i];
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += max(max(a1[i], a2[i]), a3[i]);
        cout << sum << endl;
    }
    return 0;
}
