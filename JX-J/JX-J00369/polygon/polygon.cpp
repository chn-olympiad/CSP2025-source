#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum,maxn,tot[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
       for(int i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
       }
       if(sum>maxn*2){
            ans++;
       }
       cout<<ans%998244353;
       return 0;
    }
    else{
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;i<=n-1;j++){
                tot[i][j]=a[i]+a[j];
            }
        }
        int c=n-2,cnt=-1;
        while(c--){
            cnt++;
           for(int i=1;i<=n-2;i++){
                for(int j=i+1+cnt;i<=n-1;j++){
                    tot[i][j]+=a[j+1];
                    if(tot[i][j]>a[j+1]*2){
                        ans++;
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    return 0;
}
