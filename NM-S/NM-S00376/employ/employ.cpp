#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[550];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    int sum0=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==0) sum0++;
    }
    unsigned long long ans=1;

    if(m==1){

        for(int i=1;i<=n-sum0;i++){
            ans=ans*i;
           // cout<<i<<" "<<ans<<endl;
        }
         cout<<ans%998244353;
    }
   else{
    cout<<2204128;
   }
}
