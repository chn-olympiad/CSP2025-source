#include <bits/stdc++.h>

using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i+2;j <= n;j++){
            int maxx = -1;
            int tot = 0;
            for(int k = i;k <= j;k++){
                maxx = max(maxx,a[k]);
                tot += a[k];
            }
            if(tot > maxx*2)sum++;
        }
    }
    cout << sum;
    return 0;
}
