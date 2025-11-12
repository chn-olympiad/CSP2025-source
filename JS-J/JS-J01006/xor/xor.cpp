#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N = 500010;
int a[N];
vector<pair<int,int>>g;
int lft,rgt,res = 0;
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second < y.second;
}
signed main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin >> n >> k;
   for(int i = 1;i <= n;i ++ ){
        cin >> a[i];
   }
   for(int i = 1;i <= n;i ++ ){
        int sumx = 0;
        for(int j = i;j <= n;j ++ ){
            sumx ^= a[j];
            if(sumx == k){
                g.push_back({i,j});
            }
        }
   }
   sort(g.begin(),g.end(),cmp);
   for(int i = 0;i < g.size();i ++ ){
       if(rgt < g[i].first){
           rgt = g[i].second;
           res ++;
       }
   }
   cout << res << endl;
   return 0;
}
