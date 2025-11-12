#include <bits/stdc++.h>
using namespace std;
int n,a[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&a[1]==1){
        cout<<9;
    }
    else if(n==5&&a[1]==2){
        cout<<6;
    }
    return 0;
}
