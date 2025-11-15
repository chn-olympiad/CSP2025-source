#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
using namespace std;
int main(){
    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = 0, b = 0, c = 0;
        vector<vector<int>> v(n, vector<int> (3, 0));
        vector<bool> used(n, 0);
        int it = 0;
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }
        vector<vector<int>> dp(n, vector<int> (3, 0));
        vector<vector<pair<int, pair<int, int>>>> join(n, vector<pair<int, pair<int, int>>> (3, {0, {0, 0}}));
        dp[0][0] = v[0][0], dp[0][1] = v[0][1], dp[0][2] = v[0][2];
        join[0][0] = {1, {0, 0}}, join[0][1] = {0, {1, 0}}, join[0][2] = {0, {0, 1}};
        for (int i = 1; i < n; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    if (j == 0){
                        //cout << join[i-1][k].first << ' ';
                        if (join[i-1][k].first + 1 < n/2+1){
                            if (dp[i-1][k] + v[i][j] > dp[i][j]){
                                dp[i][j] = dp[i-1][k] + v[i][j];
                                join[i][j] = join[i-1][k];
                                join[i][j].first ++;
                            }
                        } else {
                            dp[i][j] = dp[i-1][k];
                            join[i][j] = join[i-1][k];
                        }
                    } else if (j == 1){
                        //cout << join[i-1][k].second.first << ' ';
                        if (join[i-1][k].second.first + 1 < n/2+1){
                            if (dp[i-1][k] + v[i][j] > dp[i][j]){
                                dp[i][j] = dp[i-1][k] + v[i][j];
                                join[i][j] = join[i-1][k];
                                join[i][j].second.first ++;
                            }
                        } else {
                            dp[i][j] = dp[i-1][k];
                            join[i][j] = join[i-1][k];
                        }
                    } else if (j == 2){
                        //cout << join[i-1][k].second.second << ' ';
                        if (join[i-1][k].second.second + 1 < n/2+1){
                            if (dp[i-1][k] + v[i][j] > dp[i][j]){
                                dp[i][j] = dp[i-1][k] + v[i][j];
                                join[i][j] = join[i-1][k];
                                join[i][j].second.second ++;
                            }
                        } else {
                            dp[i][j] = dp[i-1][k];
                            join[i][j] = join[i-1][k];
                        }
                    }
                }
                //cout << endl;
            }
        }
        /*for (auto a : join){
            for (auto e : a){
                cout << e.first << ' ' << e.second.first << ' ' << e.second.second << ' ' << ' ';
            }
            cout << endl;
        }*/
        cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
    }
}

//dp[i][j] = max(dp[i][j], dp[i-1][k] + v[i][j]);