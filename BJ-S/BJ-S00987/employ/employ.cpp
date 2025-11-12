#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],flag;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string b;
    cin>>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)flag++;
    }
    long long ans=1;
    for(int i=flag+1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans<<endl;
    return 0;
}