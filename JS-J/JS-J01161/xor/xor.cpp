//2025CSP-J/S rp++
//please be a nice score!
#include <bits/stdc++.h>
using namespace std;

/*
make array "a" be the input
make b[i] be the a[1] xor a[2] xor ... xor a[i]
make c[i] be the count of b's number's pos
make d[i] be c[i]'s top
make dp[i] be the max answer
dp[i]=max(dp[i],dp[i-1]) dp[ {c[i][(d[i] "or" d[i]+1)]} ]=max(dp[...],dp[i]+1)
I wish it is right :)
*/

int a[500055];
int b[500055];
vector <int> c[2100011];
int d[2100011];
int dp[500055][3];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = a[i] ^ b[i - 1];
        c[b[i]].push_back(i);
        d[i] = 0;
    }
    //{a[i] xor a[i+1] xor ... xor a[j]} = {b[j] xor b[i-1]}
    for(int i = 1;i <= n;i++){
        dp[i][0] = max(dp[i][0], dp[i - 1][2]);
        dp[i][2] = max(dp[i][0], dp[i][1]);
        //we want to find {b[x] xor b[i-1]} = {k}
        //we can just find {b[x]} = {k xor b[i-1]}
        //and it's easier
        if(c[k ^ b[i - 1]].size()){
            while(d[i] < c[k ^ b[i - 1]].size() &&
                  c[k ^ b[i - 1]][d[i]] < i){
                d[i]++;
            }
            if(c[k ^ b[i - 1]][d[i]] >= i){
                dp[c[k ^ b[i - 1]][d[i]]][1] = max(dp[c[k ^ b[i - 1]][d[i]]][1],
                                                   dp[i][0] + 1);
                    //cout << "add 1 to " << c[k ^ b[i - 1]][d[i]] << "\n";
            }
        }
        //cout << "i:" << i << " dp[i][0]:" << dp[i][0] << " dp[i][1]:" << dp[i][1] << "\n";
        dp[i][2] = max(dp[i][0], dp[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}
