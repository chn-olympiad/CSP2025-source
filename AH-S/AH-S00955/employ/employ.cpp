#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++) ans*=i,ans%=998244353;
        cout<<ans;
    }
    return 0;
}
