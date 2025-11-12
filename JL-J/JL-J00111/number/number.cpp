#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","e",stdin);
    freopen("number.out","w",stdout);
    int a[1001],s[1000001];
    for (int i=0;i<=1000001;i++){
        cin >> a[i];
    }
    for (int i=0;i<=1000001;i++){
        if(a[i]=='9'){
            cout << '9';
        }
        else if(a[i]=='8'){
            cout << '8';
        }
        else if(a[i]=='7'){
            cout << '7';
        }
        else if(a[i]=='6'){
            cout << '6';
        }
        else if(a[i]=='5'){
            cout << '5';
        }
        else if(a[i]=='4'){
            cout << '4';
        }
        else if(a[i]=='3'){
            cout << '3';
        }
        else if(a[i]=='2'){
            cout << '2';
        }
        else if(a[i]=='1'){
            cout << '1';
        }
        else if(a[i]=='0'){
            cout << '0';
        }
    }
    return 0;
}
