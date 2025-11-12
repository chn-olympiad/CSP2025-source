#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
long long p=98244353;
int n,m,c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    long long ans=1;
    for(int i=n;i>=1;i--){
        ans=ans*i;
        ans%=p;
    }
    cout<<ans<<endl;
    return 0;
}
