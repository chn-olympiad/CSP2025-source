#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","e",stdin);
    freopen("number.out","w",stdout);
    int a;
    long long z[10000];
    for (int i=;i<=a;i++){
        cin >> z[i];

    }
    for (int i=;i<=a;i++){
        if(z[i]!=z[i+1]){
             cout <<z[i];
             break;
        }

    }

    return 0;
}
