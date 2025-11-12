#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int dfs(int s,int l,int r,int sum){
    if(sum>2*a[r]) ans++;
    for(int i=r+1;i<=n;i++)
        dfs(++s,l,i,sum+=a[r]);
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3&&a[3]*2<a[1]+a[2]+a[3]){
        cout<<"1";
        return 0;
    }else if(n==3&&a[3]*2>=a[1]+a[2]+a[3]){
        cout<<"0";
        return 0;
    }
    for(int i=1;i+3<=n;i++)
        ans=dfs(3,i,i+3,a[1+i]+a[2+i]+a[3+i])%998%244%353;
    cout<<ans;
    return 0;
}
