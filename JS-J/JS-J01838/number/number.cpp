#include<bits/stdc++.h>
using namespace std;
int b[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a;
    string c;
    cin>>c;
    a=c.size();
    for(int i=0;i<=a-1;i++){
        b[c[i]-47]+=1;
    }
    for(int i=10;i>=1;i--){
        for(int j=1;j<=b[i];j++){
            cout<<i-1;
        }
    }
    return 0;
}
