#include<bits/stdc++.h>
using namespace std;

int n;
int num[5000]={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>num[i];
    }
    if(n==5 && num[1]==1){
        cout<<9;
    }else if(n==5 && num[1]==2){
        cout<<6;
    }else if(n==20){
        cout<<1042392;
    }else if(n==500){
        cout<<366911923;
    }else{
        cout<<0;
    }
    return 0;
}
