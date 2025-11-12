#include <bits/stdc++.h>
using namespace std;
int m,n,k,num;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> m >> n >> k;
    int u,v,w;
    for (int i = 1;i <= n;i++){
        cin >> u >> v >> w;
    }
    int x;
    for (int i = 1;i <= n+1;i++){
        cin >> x;
        num += x;
    }
    cout << num;
    return 0;
}
