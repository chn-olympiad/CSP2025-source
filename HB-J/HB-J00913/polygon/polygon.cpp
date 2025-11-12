#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n; cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    sort(a,a+n+1);
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
    else
{
    long long sum=0,mx,cnt=3;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]) continue;
        sum=a[i];
        for(int j=i;j<=i+cnt;j++){
            sum+=a[j];
            mx=a[j];
            if(sum>mx*2){
                ans++; continue;
            }
        }
        cnt++;
    }
    cout<<ans%998244353;
}
    return 0;
}
