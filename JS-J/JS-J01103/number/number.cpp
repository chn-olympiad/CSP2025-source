#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000001],c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;

    for(int i=0;i<1000000;i++){

       if(48<=int(a[i])&&int(a[i])<=57){
            b[c]=b[c]+int(a[i]-48);
            c=c+1;
       }else if(a[i]==0){
       break;}

    }
    sort(b,b+c);
    for(int i=c-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
