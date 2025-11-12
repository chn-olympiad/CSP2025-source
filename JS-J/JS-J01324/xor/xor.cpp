#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    char special='A';
    int n;cin>>n;
    ll k;cin>>k;
    int amt1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) amt1++;
        if(a[i]>1&&special!='N') special='C';
        if(a[i]>255) special='N';
    }
    if(special=='A'){
        if(k==0) cout<<amt1/2<<endl;
        if(k==1) cout<<amt1<<endl;
    }else{
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=k) ans++; 
        }
        cout<<ans<<endl;
    }
    return 0;
}