#include <bits/stdc++.h>
using namespace std;

int a[500005];
long long res = 0;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int fa1 = 1;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] != 1){
            fa1 = 0;
        }
    }


    sort(a,a + n);
    if(n == 3) {
        if(a[2] > (a[1] + a[0])) cout << 0;
        else cout << 1;
        return 0;
    }
    if(fa1){
        for(int i = 3;i <= n;i ++){
            int res1 = 1,res2 = 1;
            for(int j = 1;j <= i;j ++){
                res1 *= j;
            }
            for(int j = n;n - j < i;j --){
                res2 *= j;
            }
            res += res2 /
        }
    }
    return 0;
}
//#Shang4Shan3Ruo6Shui4
