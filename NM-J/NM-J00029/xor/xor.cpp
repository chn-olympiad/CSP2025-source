#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
int cnt,n,k,a[M],ans[M];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 0;i < n;++ i){
        cin >> a[i];
    }
    int x;
    int l = 0,r;
    while (l < n){
        r = l;
        while (r < n){
            x = a[l];
            for (int i = l + 1;i <= r;++ i){
                x ^= a[i];
            }
            if (x == k){
                ++ cnt;
                l = r + 1;
                break;

            }
            ++ r;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
