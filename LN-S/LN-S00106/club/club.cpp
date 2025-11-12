#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][4];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        int k = n/2, sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            sum += max(a[i][1], max(a[i][2], a[i][3]));
        }
        cout << sum <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
