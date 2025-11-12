#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    char maxa='0';
    for(int i=0;i<a.length();i++){
        if('0'<=a[i]&&a[i]<='9'){
            cout<<a[i];
        }
    }

    return 0;
}

