#include<bits/stdc++.h>
using namespace std;
const int maxn = 5001;
int a[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum = 0;
    int maxx,num = 0;
    cin >> n;
    if (n < 3){
        cout << 0;
        return 0;
    }
    if(n = 3){
        maxx = a[1];
        for(int i = 2;i <= n;i++){
            maxx = max(maxx,a[i-1]);
        }
        if(a[1] + a[2] + a[3] > maxx) cout << 1;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 3;i <= n;i++){
        for(int j = i;j >= 1;j--){
            num += a[j];
            maxx = a[i];
            if(j >= 3 ){
                for(int w = i;w >= j;w--){
                    maxx = max(maxx,a[w]);
                }
                    if(num > 2 * maxx){
                        sum ++;
                    }
            }
            if (sum >= 998244353) sum = sum % 998244353;
        }
        num = 0;
    }
    cout << sum;
    return 0;
}
