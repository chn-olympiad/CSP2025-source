#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
void dfs(int i,int m,int h,int mx){
    if(m>=3&&h>mx*2){
        ans++;
        ans%=998244353;
        //cout<<m<<' '<<h<<' '<<mx<<endl;
    }
    if(i>=n){
        return;
    }
    //cout<<i<<' '<<1<<' '<<ans<<endl;
    dfs(i+1,m+1,h+a[i],max(mx,a[i]));
    //cout<<i<<' '<<0<<' '<<ans<<endl;
    dfs(i+1,m,h,mx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans-2;
    return 0;
}

