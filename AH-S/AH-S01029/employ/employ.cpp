#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=1;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
