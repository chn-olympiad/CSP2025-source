#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,b[1000000],ans;
string a;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

