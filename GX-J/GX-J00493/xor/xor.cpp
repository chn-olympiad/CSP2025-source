#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,c,b[50010],x=0;
    bool y=0;
    cin>>a>>c;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        x+=b[i];
    }
    for(int i=1;i<=a;i++){
        if(b[i]!=b[i-1]) y=1;
    }
    if(y) cout<<c;
    else if(k==0) cout<<1;
    else if(x%a==0){
        cout<<x/a;
    }
    else cout<<b[1];
    return 0;
}
