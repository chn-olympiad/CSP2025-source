#include <bits/stdc++.h>
using namespace std;
int n,m,luqu,ci;
long long ans=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>ci;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x==0)ci++;
    }
    if(n-ci<m)cout<<0;
    else{
        for(int i=ci;i<=n;i++)
            ans*=i,ans%=998244353;
        cout<<n-ci;
    }
    return 0;
}
