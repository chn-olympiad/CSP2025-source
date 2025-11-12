#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=a[1]+a[2]+a[3];
    int max_a=max(max(a[1],a[2]),a[3]);
    if(cnt>(2*max_a)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
    }
    else{
        cout<<0;
        return 0;
    }
}

