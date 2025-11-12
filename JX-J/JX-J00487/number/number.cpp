#include<bits/stdc++.h>
using namespace std;
long long b[15]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(long long i=0;i<=a.length();i++){
        if(48<=a[i] and a[i]<=57){
            b[a[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=1;j<=b[i];j++){
            cout<<i;
        }

    }
    return 0;
}
