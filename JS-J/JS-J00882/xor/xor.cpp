#include <bits/stdc++.h>

using namespace std;
int n, k;
int dfs(vector<int>& nums, vector<int>& f, int l, int r,int sum){
    if(r>n) return sum;
    return max(dfs(nums, f, l, r+1, sum), dfs(nums, f, r, r+1, sum + ((f[r]^f[l-1])==k)));
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    vector<int> nums(n+1, 0);
    vector<int> xorSum(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        xorSum[i] = xorSum[i-1] ^ nums[i];

    }
    // for(int i=1;i<=n;i++){
    //     if((xorSum[i]^xorSum[li]) == k){
    //         cout << (xorSum[i]^xorSum[li] )<< " " << i << " " << li+1 << endl;
    //         ans ++;
    //         li = i;
    //     }
    // }
    // vector<pair<int,int>> pairs;
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         if(xorSum[j]^xorSum[i-1]== k){
    //             pairs.push_back({i, j});
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
    cout << dfs(nums, xorSum, 1, 1, 0);

    int ans = 0;



    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     freopen("xor.in", "r", stdin);
//     freopen("xor.out", "w", stdout);
//     int n, k;
//     cin >> n >> k;
//     vector<int> nums(n+1, 0);
//     vector<int> xorSum(n+1, 0);
//     for(int i=1;i<=n;i++){
//         cin >> nums[i];
//         xorSum[i] = xorSum[i-1] ^ nums[i];

//     }
//     int ans = 0;
//     for(int j=1;j<=n;j++){
//         int sum = 0, li = 0;
//         for(int i=j;i<=n;i++){
//             if((xorSum[i]^xorSum[li]) == k){
//                 sum ++;
//                 li = i;
//             }
//         }
//         ans = max(ans, sum);
//     }



//     cout << ans;

//     return 0;
// }
