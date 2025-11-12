#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n;
int cnt;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n <= 3){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int k = j + 1;k <= n;k++){
                    int maxn = max(max(a[i],a[j]),max(a[j],a[k]));
                    if((a[i] + a[j] + a[k]) > maxn * 2){
                        cnt++;
                    }
                }
            }
        }
        cout << cnt % 998244353;
    }
    return 0;
}
