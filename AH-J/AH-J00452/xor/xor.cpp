/*#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005],f[500005];
map<int,int> mp;
signed main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,k,maxn=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=a[i]^sum[i-1];
    }
    for(int i=1;i<=n;i++){
        f[i]=maxn;
        int liming=sum[i]^k;
        if(mp.count(liming)){
            f[i]=max(f[i],f[mp[ng]]);
        }
        mp[sum[i]]=i;
        maxn=max(maxn,f[i]);
    }
    cout<<maxn;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,maxn=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        int cnt=0;
        for(int r=l;r<=n;r++){
            int sum=a[l];
            for(int i=l+1;i<=r;i++){
                sum=sum^a[i];
            }
            if(sum==k){
                cnt++;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
