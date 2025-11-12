#include <bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    int f = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1)f = 1;
    }
    int sum = 0;
    if(k == 0 and f == 0)sum = n/2;
    else{
        if (k == 1){
            for(int i = 1;i <= n;i++){
                if(a[i] == 1)sum++;
            }
        } else {
            if(a[1] == 0)sum++;
            for(int i = 2;i <= n;i++){
                if(a[i] == 0)sum++;
                else if(a[i] == 1 && a[i-1] == 1){
                    sum++;
                    a[i] = 0;
                }
            }
        }
    }
    cout << sum;
    return 0;
}
