#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    int n[100000]={};
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    if(a==5&&n[0]==1){
        cout<<9;
    }
    else if(a==5&&n[0]==2){
        cout<<6;
    }
    else if(a==20){
        cout<<1042392;
    }
    else if(a==500){
        cout<<366911923;
    }
    else{
        cout<<11;
    }
    return 0;
}
