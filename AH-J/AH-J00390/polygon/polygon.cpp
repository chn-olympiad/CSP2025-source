#include<bits/stdc++.h>
using namespace std;
int n,a[10000],sum[10000],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int maxn=0;
            for(int x=i;x>=j;x++){
                maxn=max(maxn,a[x]);
            }
            if(sum[j]-sum[i-1]>maxn*2){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
