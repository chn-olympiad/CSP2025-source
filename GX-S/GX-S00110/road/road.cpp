#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int n, m, k;
vector<int> g[MAXN];
struct edges{
    int head;
    int nxt;
    int val;
}ed[MAXN];
bool cmp(edges a, edges b){
    return a.val < b.val;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >>m >>n >> k;
    for (int i = 1; i <= m; i++){
        cin >> ed[i].head >> ed[i].nxt >> ed[i].val;
    }
    for (int i = 1; i <= k; i++){
        int temp;
        cin >>temp;
        for (int i = 1; i <= n; i++)
            cin >>temp;
    }
    sort(ed+1, ed+m+1, cmp);
    int ans = 0;
    for (int i = 1; i <= n-1; i++){
        ans+=ed[i].val;
    }
    cout << ans;
    return 0;
}
