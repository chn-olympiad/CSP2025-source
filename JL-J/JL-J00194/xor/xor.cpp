#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> sm(n + 1); sm[0] = 0;
    vector<int> lis(n + 1);
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        scanf("%d", &lis[i]);
        sm[i] = (sm[i - 1] ^ lis[i]);
    }
    for(int i = 1; i <= n; i++){
        if(lis[i] == k){
            dp[i] = dp[i - 1] + 1;
            continue;
        }
        dp[i] = max(dp[i], dp[i - 1]);
        for(int j = i + 1; j <= n; j++){
            dp[j] = max(dp[j], dp[i - 1]);
            if(lis[j] == k) break;
            if((sm[j] ^ sm[i - 1]) == k){
                dp[j]++;
                break;
            }

        }
    }
    //cout << endl;
    //for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << dp[n];
    return 0;
}

/*
4 3
2 1 0 3
2
*/
