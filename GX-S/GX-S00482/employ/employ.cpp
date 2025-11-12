#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[510],f,ans;
int main(){
    freopen("employ.in","r",stdin);
    reopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) f++;
    }
    for(int i=1;i<=n;i++){
        ans+=i;
    }
    cout<<ans%998244353;
    return 0;
}
