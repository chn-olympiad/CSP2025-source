#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int maxn=0,sum=0;
        for(int i=1;i<=3;i++){
            maxn=max(maxn,a[i]);
            sum+=a[i];
        }
        if(sum>maxn*2) cout<<1;
        else cout<<0;
    }
    bool b=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1) b=1;
    }
    if(b==0){
        int ans=0;
        for(int i=3;i<=n;i++){
            int sum=1;
            for(int j=n;j>=n-i+1;j--) sum*=j;
            for(int j=i;j>=1;j--) sum/=j;
            ans+=sum;
        }
        cout<<ans;
    }
    return 0;
}
