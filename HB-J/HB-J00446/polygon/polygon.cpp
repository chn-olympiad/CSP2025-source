#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans,maxn,sum,n;
const int MOD=998244353;
void dfs(int ii){
    if(ii>n){
        if(sum>maxn)
            ans++;
        if(ans>=MOD)
            ans-=MOD;
        return;
    }
    for(int i=ii;i<=n;i++){
        sum+=a[i];
        dfs(i+1);
        sum-=a[i];
    }
    dfs(n+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bool AllIsOne=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            AllIsOne=false;
    }
    if(AllIsOne){
        cout<<(((int)(pow(2,n))%MOD)-n-((n*(n-1)/2)%MOD)-1)%MOD<<"\n";
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n-2;i++){
        maxn=a[i];
        dfs(i+1);
    }
    cout<<ans;
    return 0;
}
