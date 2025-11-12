#include<bits/stdc++.h>
using namespace std;
long long n,k,a,q[500009],ans[500009];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a,q[i]=q[i-1]^a;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            int c=0;
            if((q[i]^q[j])==k)c=1;
            ans[i]=max(ans[i],ans[j]+c);
        }
    }cout<<ans[n];
}
