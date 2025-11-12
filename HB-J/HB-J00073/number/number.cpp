#include <bits/stdc++.h>
using namespace std;
string a;
int b[10];
int main(){
    cin>>a;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<a.size();i++){
        if('0'<=a[i]<='9')
            b[int(a[i]-48)]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
    return 0;
}
