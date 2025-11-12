#include <bits/stdc++.h>
using namespace std;
long long n,k,sum = 0;
long long a[100000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(k == 1){
        for(int i = 1;i <= n;i++){
            if(a[i] == 1){
                sum++;
            }
        }
    }else if(k == 0){
       for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
