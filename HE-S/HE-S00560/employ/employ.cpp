#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string d;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=n;i>=2;i--){
        ans*=i;
        ans%=998244353;
    }cout<<ans;
    return 0;
}
