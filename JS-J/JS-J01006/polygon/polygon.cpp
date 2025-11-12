#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5010];
vector<int>k;
const int Mod = 998244353;
int cnt = 0;
void dfs(int x,vector<int> v){
    if(x == n + 1){
        if(v.size() < 3)return;
        int sum = 0,maxn = 0;
        for(int i = 0;i < v.size();i ++ ){
            sum += v[i];
            maxn = max(maxn,v[i]);
        }
        cnt += (maxn * 2 < sum);
        return;
    }
    v.push_back(a[x]);
    dfs(x + 1,v);
    v.pop_back();
    dfs(x + 1,v);
}
signed main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin >> n;
   for(int i = 1;i <= n;i ++ ){
        cin >> a[i];
   }
   dfs(1,k);
   cout << cnt % Mod << endl;
   return 0;
}
