#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1145141;
int n,k;
int a[M],dp[M],maxn[M];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    maxn[0]=a[1];
    for(int l=1;l<=n;l++){
        for(int r=n;r>=l;r--){
            cnt++;
            int sum=a[l];
            for(int i=l+1;i<=r;i++){
                sum^=a[i];
            }
            maxn[cnt]=sum;
        }
    }
    sort(maxn+1,maxn+n*n+1);
    cout<<maxn[n*n];
    return 0;
}
