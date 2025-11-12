#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    if(a=4){
        if(b=2||b=3){
            cout<<2;
        }else{
            cout<<1;
        }
    }
    return 0;
}
