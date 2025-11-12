#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[1000001];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
    bool is0=false;

    for(long long i=1;i<n;i++){
        cin>>a[i];
        a[0]=a[1];
        if(a[i]==a[i-1]){
            is0=true;
        }
    }
    if(is0){
        for(int i=n-1;i>=1;i--){
            ans+=i;
        }
    }
    cout<<ans;
    return 0;
}
