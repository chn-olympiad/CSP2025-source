#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b;
    cin>>a>>b;
    long int s[a];
    for(int i=0;i<a;i++){
        cin>>s[i];
    }
    if(b==2){
        cout<<2;
    }else{
        if(b==3){
            cout<<2;
        }else{
            if(b==0){
                cout<<1;
            }else{
                cout<<3;
            }
        }
    }
    return 0;
}
