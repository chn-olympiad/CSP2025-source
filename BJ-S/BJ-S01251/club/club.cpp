#include <bits/stdc++.h>
using namespace std;
long long m,n,a[99999],maxn;
int main(){
    freopen("club.in""s"stdin);
    freopen("club.out""w"stdout);
    cin>>m;
    for(int j=1;j<=m;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn+=max(maxn,a[i]);
        }
        printf("%d\n",maxn);
    }
    return 0;
}
