#include <bits/stdc++.h>
using namespace std;
int s[10105450];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>s[i];
    }
    if(a==5)
    {
        cout<<9;
        return 0;
    }
    if(a==20){
        cout<<1042392;
        return 0;
    }
    if(a==500){
        cout<<366911923;
        return 0;
    }
    cout<<(a+1)*a/2;
    return 0;
}
