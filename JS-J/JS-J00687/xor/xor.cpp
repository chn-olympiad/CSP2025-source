#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum[500005];
int ha[10000005];
int l=0;
int ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<=10000000;i++)ha[i]=-1;
    ha[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];

        if(((ha[sum[i]^k]>=l&&ha[sum[i]^k]<i&&sum[i-1]!=0)||(sum[i-1]==0&&a[i]==k))){
            l=i;
            ans++;

        }
        ha[sum[i]]=max(ha[sum[i]],i);
//cout<<i<<" "<<ha[sum[i]^k]<<" "<<(sum[i]^k)<<" "<<sum[i]<<'\n';
  //      cout<<sum[i]<<" ";
    }
    cout<<ans;
    return 0;
}
