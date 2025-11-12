#include <bits/stdc++.h>
using namespace std;

int a[500005],s[500005];
bool flag[500005];
int n,k,fa1 = 1;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin >> n;
    cin >> k;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        if(a[i] != 1){
            fa1 = 0;
        }
    }
    if(k == 0){
        if(fa1){
            cout << n;
            return 0;
        } else {
            //10 0 1 0 0 1 0 1 0 1 1 0
            cout << n;
            return 0;
        }
    }
    //cout << k << endl;
    //if(k == 1){
        //10 0 1 0 0 1 0 1 0 1 1 0
    //    int res = 0;
    //   for(int i = 0;i < n;i ++){
    //        if(a[i] == 0 && !(flag[i])) {
    //            if((a[i - 1] != 1 || flag[i - 1]) || i - 1 < 0) {
    //                if(a[i + 1] != 1|| i + 1 >= n) {
    //                    continue;
    //                } else {
    //                    res ++;
    //                    flag[i] = 1;
    //                    flag[i + 1] = 1;
    //                }
    //            } else {
    //                res ++;
    //                flag[i] = 1;
    //                flag[i - 1] = 1;
    //            }
    //        }
    //    }
    //    cout << res;
    //    return 0;
    //}
    for(int i = 0;i < n;i ++){
        s[i + 1] = a[i] ^ s[i];
        //cout << s[i + 1] << ' ';
    }
    long long res = 0;
    for(int i = 1;i <= n;i ++){
        if(!flag[i]){
            int j;
            int fje = 0;
            for(j = i;j <= n && flag[j] == 0;j ++){
                flag[j] = 1;
                if((s[j] ^ s[i - 1]) == k){
                    fje = 1;
                    break;
                }
            }
            if(fje){
                res ++;
                //cout << i << ' ' << j << endl;
            }
        }
    }
    cout << res;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
