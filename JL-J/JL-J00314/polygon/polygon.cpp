#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<"0";
    }
    if(n==3){
        c=max(a[1],a[2]);
        c=max(a[3],c);
        if((a[1]+a[2]+a[3])>(2*c)){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}
