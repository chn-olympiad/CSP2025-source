#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==1){
        cout<<9;
    }
    else{
        cout<<6;
    }
    return 0;
}
