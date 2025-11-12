#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int num = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            num++;
            if(a[i] > 1){
                num = 1000000000;
            }
        }
    }
    if(num == 0){
        if(k == 0){
            cout << n / 2;
        }
        else if(k == 1){
            cout << n;
        }
        else{
            cout << "0";
        }
    }
    else if(num < 100000000){
        int sum = 0;
        if(k == 0){
            bool flag[n + 1] = {false};
            flag[0] = true;
            for(int i = 1;i <= n;i++){
                if(a[i] == 0){
                    sum++;
                    flag[i] = true;
                }
                else{
                    if(flag[i - 1] == false){
                        flag[i] = flag[i - 1] = true;
                        sum++;
                    }
                }
            }
            cout << sum;
        }
        else{
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                   sum++;
                }
            }
            cout << sum;
        }
    }
    else{
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == k){
                ans++;
            }
        }
        cout << ans;
    }

    return 0;
}
