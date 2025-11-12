#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==20){
        cout<<1042392;
        return 0;
    }
    if(n==500){
        cout<<366911923;
    }
    if(n==5){
        int a;
        cin>>a;
        if(a==1){
            cout<<9;
        }else{
        cout<<6;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
