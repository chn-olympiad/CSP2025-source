#include<bits/stdc++.h>
using namespace std;
int m[3000000];
int k,n,t,r,ans,a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    r=1;
    for(int i=1;i<=n;i++){
        t=t^a[i];
        if(m[t^k]==r || t==k){
            ans++;
            r++;
            t=0;
        }
        else{
            m[t]=r;
        }
    }
    cout<<ans;
    return 0;
}
