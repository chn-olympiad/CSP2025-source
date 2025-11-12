#include <bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int m = 0, num;
int ans = 0;
int l,t;
void dfs(int now, int sum, int sid, int k){
    if(now == k){
        if(sum > m*2){
            ans++;
            m = 0;
        }
        else{
            m = 0;
        }
        return ;
    }

    for(int i = sid; i <= n-k+now+1; i++){
        if(a[i] > m) m = a[i];
        dfs(now+1, sum+a[i], i+1, k);
    }
    return ;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        a[i] = num;
    }

    for(int i = 1; i <= n-1; i++){
        for(int j = 2; j <= n; j++){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }

    for(int i = 3; i <= n; i++){
        dfs(0,0,1,i);
    }
    cout << ans%998244353;
    return 0;
}
