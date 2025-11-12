#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
bool subtaska = true,subtaskb = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (long long i = 0;i < n;i++){
        cin >> a[i];
        if (a[i] != 1){
            subtaska = false;
        }
        if (a[i] > 1){
            subtaskb = false;
        }
    }
    if (subtaska){
        cout << n / 2;
        return 0;
    }
    if (subtaskb){
        long long ans = 0;
        if (k == 0){
            for (long long i = 0;i < n - 1;i++){
                if (a[i] == a[i + 1]){
                    ans++;
                    i++;
                }
                else{
                    if (!a[i]){
                        ans++;
                    }
                    else if ((i < n - 2) && a[i + 2]){
                        ans++;
                        i += 2;
                    }
                }
            }
            cout << ans;
            return 0;
        }
        for (long long i = 0;i < n - 1;i++){
            if (a[i] != a[i + 1]){
                ans++;
                i++;
            }
            else{
                if (a[i]){
                    ans++;
                }
                else if ((i < n - 2) && a[i + 2]){
                    ans++;
                    i += 2;
                }
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}
