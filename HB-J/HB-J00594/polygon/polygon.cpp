#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,nc[5010],a[5010];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> nc[i];
    }
    sort(nc,nc + n);
    int ans = 0,i = 0,j = 2;
    while(j < n){
        int f = 0;
        for(int ii = i;ii < j;ii++){
            f += nc[ii];
        }
        if(f > 2 * nc[j]){
            ans++;
            i++,j++;
        }else{
            j++;
        }
    }
    cout << ((ans % 998) % 224) % 353;
    return 0;
}
