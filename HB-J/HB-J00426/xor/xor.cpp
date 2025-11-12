#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n , k, ans;
int arr[N];

void dfs(int depth,int t){
    if(depth >= n){
        ans = max(ans, t);
        return;
    }

    for(int i = depth;i <= n;i ++){
        dfs(i + 1, t);
        int res = 0;
        for(int j = depth;j < i;j ++){
            res = arr[j] ^ arr[j + 1];
        }
        if(res == k){
            dfs(i + 1, t + 1);
        }
    }
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> arr[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
