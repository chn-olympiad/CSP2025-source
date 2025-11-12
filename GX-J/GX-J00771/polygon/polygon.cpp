#include<bits/stdc++.h>
using namespace std;
long long Mod=998244353;
long long n,arr[5010],qian[5010],sum,ans=0,maxx;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    qian[0]=0;
    for(int i=1;i<=n;i++)qian[i]=qian[i-1]+arr[i];
    for(int i=1;i<=n-3;i++){
        for(int j=i+2;j<=n;j++){
            sum=qian[j]-qian[i-1],maxx=arr[j];
            if(sum>maxx*2)ans=(ans+1)%Mod;
        }
    }
    cout<<ans;
    return 0;
}
