#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long f[500005];
map<long long,long long> mp;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=0;
    f[1]=a[1];
    for(long long i=2;i<=n;i++){
        f[i]=f[i-1]^a[i];
    }
    long long ans=0;
    long long l=0;
    for(long long i=1;i<=n;i++){
        long long need=k^f[i];
        if(need==0 && mp[0]==0 && mp[0]>=l){
            ans++;
            l=i;
            mp[0]=-1;
        }
        else if(mp[need]!=0 && mp[need]>=l){
            ans++;
            l=i;
            mp[need]=0;
        }
        //else{
            mp[f[i]]=i;
        //}
    }
    cout<<ans;
    return 0;
}
