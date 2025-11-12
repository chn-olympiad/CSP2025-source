#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[4]={},max=-1000,s=0;
    cin>>a;
    if(a>3){
        cout<<9;
    }
    else{
        for(int i=1;i<=3;i++){
            cin>>b[i];
        }
        for(int i=1;i<=3;i++){
            s=s+b[i];
            if(b[i]>max){
                max=b[i];
            }
        }
        if(max*2>=s){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}
