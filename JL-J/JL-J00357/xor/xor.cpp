#include <bits/stdc++.h>
using namespace std;
int a[200001];
bool vis[200001];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    bool flag = true;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1)
            flag = false;
    }
    if (flag)
        cout << n / 2;
    else if (k <= 1){
        if (k == 0) {
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (a[i] == 0)
                    cnt++;
                else
                    vis[i] = true;
            }
            for (int i = 2; i <= n; i++) {
                if (vis[i] && vis[i - 1]){
                    vis[i] = false;
                    vis[i - 1] = false;
                    cnt++;
                }
            }
            cout << cnt;
        } else {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] == 1)
                    cnt++;
            cout << cnt;
        }
    } else
        cout << "CSP you have no egg!!!!!!!!!";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
