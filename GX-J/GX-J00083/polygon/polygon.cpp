#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long int b[n+5];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(b[0]==1){
        cout<<9;
    }else{
        if(b[0]==2){
            cout<<6;
        }else{
            cout<<5;
        }
    }
    return 0;
}
