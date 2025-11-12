#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char z[1000005]={' '};
    long long a[15];
    cin>>z;
    for(int i = 0;i <= 1000005;i++){
        if(z[i] == '0'){
            a[0]++;
        }
        if(z[i] == '1'){
            a[1]++;
        }
        if(z[i] == '2'){
            a[2]++;
        }
        if(z[i] == '3'){
            a[3]++;
        }
        if(z[i] == '4'){
            a[4]++;
        }
        if(z[i] == '5'){
            a[5]++;
        }
        if(z[i] == '6'){
            a[6]++;
        }
        if(z[i] == '7'){
            a[7]++;
        }
        if(z[i] == '8'){
            a[8]++;
        }
        if(z[i] == '9'){
            a[9]++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
