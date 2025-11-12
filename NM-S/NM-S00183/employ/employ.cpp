#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    cout<<ans;
    return 0;
}
