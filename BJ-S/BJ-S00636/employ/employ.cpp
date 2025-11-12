#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,sum=1,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n<m)
        cout<<"0"<<endl;
    else{
        for(int i=1;i<=n;i++){
            sum=((sum%mod)*(i%mod))%mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
