#include<bits/stdc++.h>
#define int long long
using namespace std;
int pack[25000050];
int mod=998244353;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    int a[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        pack[a[i]]++;
    }
    sort(a,a+n);
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int maxj=0;pack[0]=1;
    for(int i=0;i<=sum[n-1]/2;i++){
        int j=0;
        while(a[j]<i/2)j++;
        int l=j;
        while(a[j]==i/2)j++;
        for(;a[j]<i;j++){
            if(pack[i-a[j]]!=0){
                pack[i]+=pack[i-a[j]];
            }
        }
        if(a[l]==i/2&&i%2==0){
            pack[i]+=pack[i/2]*(pack[i/2]-1)/2;
        }
        pack[sum[n-1]-i]=pack[i];
    }
    //for(int i=0;i<=sum[n-1];i++)cout<<pack[i]<<' ';
    int ans=0;
    for(int i=n;i>=2;i--){
        for(int j=i+1;j<=sum[i-2];j++){
            if(pack[j]-pack[j-i]>0){
                ans+=max((int)0,pack[j]-pack[j-i]);
                if(j-i>=i)ans--;
                //cout<<ans<<" ";
                ans%=mod;
            }
        }
    }
    cout<<ans%mod;
    return 0;
}
