#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin >> n >> k;
    int a[500005] = {};
    bool flag = 1;
    bool flag2 = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            flag = 0;
        }
        else if(a[i] != 1 || a[i] != 0){
            flag2 =0;
        }
    }
    if(flag == 1){
        cout << n / 2;
        return 0;
    }
    else if(flag2 == 1){
        if(k == 1){
            int sum = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                    sum +=1;
                }
            }
            cout << sum;
        }
        else if(k == 0){
            int di1 = 0;
            int di2 = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                    di1++;
                }
                if(a[i] == 0){
                    di2++;
                }
            }
            cout << di1 / 2 + di2;
        }
        return 0;
    }
    return 0;
}

