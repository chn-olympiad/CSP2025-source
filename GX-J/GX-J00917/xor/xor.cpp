#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,k,ans,num;
long long a[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==1) ans++;
            if(a[i]==0) num++;
        }
        cout<<ans/2+num;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) ans++;
            if(a[i]==0) num++;
        }
        cout<<ans;
    }
    return 0;
}
