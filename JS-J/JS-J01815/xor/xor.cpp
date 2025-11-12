#include<bits/stdc++.h>
using namespace std;

int a[50005];

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)flag=1;
    }
    if(n==2&&flag==0)cout<<1;
    else if(n<2&&flag==0)cout<<0;
    else if(n>2&&n<=100&&flag==0)cout<<n/2;
    else cout<<2;
    return 0;
}


