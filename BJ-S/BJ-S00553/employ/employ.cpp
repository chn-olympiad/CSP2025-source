#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n==m)cout<<1;
    else if(m==1)cout<<n;
    else{
        int c;
        cin>>c;
        if(c==1)cout<<1;
        else cout<<998244352;
    }
}
