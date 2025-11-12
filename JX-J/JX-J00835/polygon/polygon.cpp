#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
int lst[100];

void dfs(int x, int sm, int ind){
    if(ind>=0){
        if(x>=2&&sm>lst[ind]){
            ans++;
        }
    }
    for(int i=ind+1; i<n; i++){
        dfs(x+1, sm+lst[ind], i);
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>lst[i];
    }
    sort(lst, lst+n);
    dfs(0, 0, -1);
    cout<<ans%998244353;
    return 0;
}
