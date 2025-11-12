#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,sum1,sum2,sum3,f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 0 && a[i] != 1){
            f = 1;
        }
        if(!f){
            sum2 += a[i];
        }
        s ^= a[i];
        if(s == k){
            sum1++,s = 0;
        }
    }
    if(!f){
        cout << sum2 / (!k + 1);
    }else if(n <= 10000){
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                s ^= a[j];
                if(s == k){
                    i = j + 1;
                    sum3++;
                }
                s = 0;
            }
        }
        cout << sum3;
    }else{
        cout << sum1;
    }
    return 0;
}
