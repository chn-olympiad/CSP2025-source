#include <bits/stdc++.h>
using namespace std;
int n,m,dif[550],num=0;
long long ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dif[i];
        if(dif[i]==0)num++;
    }
    for(int i=n;i>=1;i--){
        ans=ans*i%998244353;
    }
    if(m+num>n)cout<<0;
    else cout<<ans;
    return 0;
}
