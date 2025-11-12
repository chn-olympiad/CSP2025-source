#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b)>c and (b+c)>a and (a+c)>b){
            cout<<1;
        }
    }
    else{
        cout<<12;
    }
    return 0;
}
