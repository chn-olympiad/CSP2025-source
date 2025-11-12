#include <bits/stdc++.h>
using namespace std;

int n,k;
const int N = 5e5 + 3,V = 2e6 + 3;
int a[N],d[N];
vector<int> t[V];
vector<pair<int,int>> q;
long long ans = 0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        d[i] = d[i - 1] ^ a[i];
    }
    for(int i = n;i >= 1;i--){
        t[d[i]].push_back(i);
    }
    for(int i = 1;i <= n;i++){
        int ned = k ^ d[i - 1];
        if(t[ned].size() > 0){
            q.push_back({i,t[ned].back()});
        }
        t[d[i]].pop_back();
    }
    sort(q.begin(),q.end(),[](pair<int,int> x,pair<int,int> y){ return x.second < y.second; });
    int last = 0;
    for(int i = 0;i < (int)q.size();i++){
        if(q[i].first > last){
            ans++;
            last = q[i].second;
        }
    }
    printf("%lld",ans);
    return 0;
}