#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],sum,ans;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int m=n;
    sort(a+1,a+1+n);
    while(m--&&m>=3){
        int maxn=0;
        sum=0;
        for(int i=1;i<=n-m+1;i++){
            for(int j=i;j<=m;j++){
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
            if(sum>2*maxn) ans++;
        }
    }cout<<ans;
    return 0;
}
