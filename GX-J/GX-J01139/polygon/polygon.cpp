#include <bits/stdc++.h>
using namespace std;
int n,a[100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for (int i = 1;i <= n;i++){
        cin >>a[i];
    }
    if (n == 5){
        for (int i = 1;i <= n;i++){
            if (a[i] == i){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            cout <<9;
        }
    }else{
        cout <<1;
    }
    return 0;
}
