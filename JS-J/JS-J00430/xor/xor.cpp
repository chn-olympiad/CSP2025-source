
#include<bits/stdc++.h>
using namespace std;
//struct node{
 //   int left, right;
//}db[260];
//bool bmp(node pre, node nxt){
//    if(pre.right != nxt.right)return pre.right < nxt.right;
//    return pre.left < nxt.left;
//}
int qzh[260], dp[260], a[260], n, k, top;
int main(){
    freopen("xor.in", "r",stdin);
    freopen("xor.out", "w",stdout);
    map<int, int>mp;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mp[i] = 0;
    }
    qzh[1] = a[1];
    int t;
    for(int i = 2;i <= n;i++){
        t = a[i] ^ qzh[i - 1];
        qzh[i] = t;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(qzh[j] -( qzh[i] - qzh[i - 1]) == k){
            //    db[++top].left = i, db[top].right = j;
                mp[j] = i;
            }
            if(qzh[i] == k) mp[i] = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(mp[i]!= 0)
        dp[i] = max(dp[i - 1],dp [i - mp[i]] + 1);
        else dp[i] = dp[i - 1];
    }
    cout << dp[n];
}
