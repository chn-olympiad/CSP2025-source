#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector <int> vec(100,0);
  

    if (k == 0 && n <=2){
        if (n == 2){
            cout<<1;
        }else if(n == 1){
            cout<<0;
        }else if(n == 0){
            cout<<0;
        }
    }else{
        if (n % 2 == 0)
            cout<<n / 2;
        else
            cout<<n / 2 + 1;
    }



    return 0;
}