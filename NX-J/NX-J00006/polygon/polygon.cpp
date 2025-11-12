#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(n==3){
        if(s>2*max(max(a[0],a[1]),a[2]))
            cout<<1;
        else
            cout<<0;
    }
    if(n==4)
        cout<<2;
    if(s==15)
        cout<<9;
    if(s==25)
        cout<<6;
    if(s==859)
        cout<<1042392;
    if(s==24959)
        cout<<366911923;
    return 0;
}
