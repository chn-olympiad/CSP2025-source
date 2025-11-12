#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000001], c = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i = 0;i < a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[c] = a[i] - '0';
            c++;
        }
    }
    sort(b, b + c);
    for(int i = c - 1;i >= 0;i--){
        cout<<b[i];
    }
    return 0;
}
