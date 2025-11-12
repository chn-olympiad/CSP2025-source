#include <bits/stdc++.h>
using namespace std;
int T, n, cnt[5];
long long anso = 0, sume = 0;
int t[200005][5], oovt[200005];
void dfs(int cur){
    if (cur == n + 1){
        anso = max(anso, sume);
        return;
    }
    for (int i = 1; i <= 3; i++){
        if (cnt[i] >= n / 2) continue;
        cnt[i]++;
        sume += t[cur][i];
        dfs(cur + 1);
        sume -= t[cur][i];
        cnt[i]--;
    }
    return;
}
void onlyonevalue(){
    sort(oovt + 1, oovt + n + 1, greater<int>());
    for (int i = 1; i <= n / 2; i++){
        anso += oovt[i];
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        bool flagg = 1;
        for (int i = 1; i <= n; i++){
            cin >> t[i][1] >> t[i][2] >> t[i][3];
            oovt[i] = t[i][1];
            if (t[i][2] != 0 || t[i][3] != 0) flagg = 0;
        }
        sume = 0, anso = 0;
        if (flagg){
            onlyonevalue();
            cout << anso << "\n";
            continue;
        }
        cnt[1] = cnt[2] = cnt[3] = 0;
        if (n < 30)
            dfs(1);
        else{
            for (int i = 1; i <= n; i++){
                if (t[i][1] > t[i][2] && t[i][1] > t[i][3] && cnt[1] < n / 2)
                    anso += t[i][1], cnt[1]++;
                else if (t[i][2] > t[i][1] && t[i][2] > t[i][3] && cnt[2] < n / 2)
                    anso += t[i][2], cnt[2]++;
                else if (t[i][3] > t[i][1] && t[i][3] > t[i][2] && cnt[3] < n / 2)
                    anso += t[i][3], cnt[3]++;
                else{
                    if (cnt[1] < cnt[2] && cnt[1] < cnt[3]) cnt[1]++, anso += t[i][1];
                    else if (cnt[2] < cnt[1] && cnt[2] < cnt[3]) cnt[2]++, anso += t[i][2];
                    else cnt[3]++, anso += t[i][3];
                }
            }
        }
        cout << anso << "\n";
    }
    return 0;
}
