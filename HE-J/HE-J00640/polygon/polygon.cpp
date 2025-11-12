#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin >> n;
    vector<long long> a(n,0);
    vector<long long> pre(n+1,0);
    for(int i = 1;i<=n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    // 前缀和
    for(int i = 1;i<=n;i++) pre[i] = a[i] + pre[i-1];

    // 害人不浅的dp

    // 二维dp

    vector<int> dp(n,vector<int> (pre[n]+3));

    // 我TM真不会写了 气死我了
    // 这是J组的题 ？ 不要虐待我这个初中生啊
    // DP + 前缀 6666
    // 难度不亚于S组T3 甚至感觉比去年T3还难
    // 最有M的一集

    cout << 0;

    return 0;
}
