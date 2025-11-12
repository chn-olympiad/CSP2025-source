#include<bits/stdc++.h>
using namespace std;
int a[100005];
int maxn = 0;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(a, sizeof(a), 0);
        maxn = 0;
        int n;
        cin >> n;
        int n3 = 3 * n;
        for(int i = 1; i <= n3; i++){
            cin >> a[i];
        }
        sort(a+1, a + n3 + 1);
        for(int i = n3; i >= n3 - n + 1; i--){
            maxn += a[i];
        }
        cout << maxn << "\n";
    }
    return 0;
}
