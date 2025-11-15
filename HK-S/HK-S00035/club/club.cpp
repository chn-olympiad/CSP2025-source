#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("club.in");
    ofstream cout("club.out");
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 1][3];
        for(int i = 1; i <= n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        int cnt[3] = {0};
        int res = 0;
        int chose[n + 1];
        for(int i = 1; i <= n; i++){
            int mx = max(max(a[i][0], a[i][1]), a[i][2]);
            if(a[i][0] == mx) chose[i] = 0;
            else if(a[i][1] == mx) chose[i] = 1;
            else chose[i] = 2;
            res += mx;
            for(int j = 0; j < 3; j++){
                if(a[i][j] == mx){
                    cnt[j]++;
                    break;
                }
            }
        }
        for(int j = 0; j < 3; j++){
            if(cnt[j] <= n / 2) continue;
            int x = (j + 1) % 3;
            int y = (j + 2) % 3;
            vector<int> vec;
            for(int i = 1; i <= n; i++){
                if(chose[i] != j) continue;
                vec.push_back(a[i][j] - max(a[i][x], a[i][y]));
            }
            sort(vec.begin(), vec.end());
            for(int i = 0; i < cnt[j] - n / 2; i++){
                res -= vec[i];
            }
        }
        cout << res << '\n';
    }
    return 0;
}