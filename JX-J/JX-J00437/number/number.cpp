#include<bits/stdc++.h>
using namespace std;
string a;
int b[100001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        b[a[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
    return 0;
}
