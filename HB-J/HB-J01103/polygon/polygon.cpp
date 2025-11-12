#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,ans,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            sum=0,maxn=-1;
            for(int k=i;k<=j;k++)maxn=max(maxn,a[k]);
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum>maxn*2){
                ans++;
                ans%=998244353;
            }
        }
    }
    cout<<ans%998244353;
    return 0;
}



//1 1 1 1 1
