#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], x;
long long l[500005], r[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans[500005];
    for (int i = 1; i <= n; i++){
        ans[i] = a[i];
        if (a[i] == k){
            x++;
            l[x] = i, r[x] = i;
        }
        for (int j = i + 1; j <= n; j++){
            ans[j] = ans[j - 1] ^ a[j];
            if (ans[j] == k){
                x++;
                l[x] = i, r[x] = j;
            }
        }
    }
    long long res=x;
    for (int i = 2; i <= x; i++){
        if (l[i - 1] >= l[i] && l[i - 1] <= r[i]){
            res--;
            if(r[i-1]-l[i-1] < r[i]-l[i]){
                r[i] = r[i - 1],l[i]= l[i-1];
            }
        }
        else if (l[i - 1] <= l[i] && l[i] <= r[i-1]){
            res--;
            if(r[i-1]-l[i-1] < r[i]-l[i]){
                r[i] = r[i - 1],l[i]= l[i-1];
            }
        }
    }
    cout << res;
    return 0;
}
