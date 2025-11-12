#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[10001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
    }
    else if(n==3){
            cout<<1;
    }
    return 0;
}
