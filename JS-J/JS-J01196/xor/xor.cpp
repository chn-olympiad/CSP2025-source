#include<bits/stdc++.h>
using namespace std;
long long n,k,lst,cnt;
long long a[500005];
long long xorsum[500005];
map<long long,long long> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    mp[0]++;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        xorsum[i]=xorsum[i-1]^a[i];
        if(mp.find(k^xorsum[i])!=mp.end())
        {
            cnt++;
            mp.clear();
        }
        mp[xorsum[i]]++;
    }
    cout<<cnt;

    return 0;
}
