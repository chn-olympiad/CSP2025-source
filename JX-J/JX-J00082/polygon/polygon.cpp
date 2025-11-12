#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int zsum=0;

long long ans=0;
void dfs(int i,int sum,int maax){
    if(i>n){
        if(sum>maax*2)ans++;
        ans%=998244353;
        return;
    }
    if(zsum<=maax*2)return;
    dfs(i+1,sum,maax);
    dfs(i+1,sum+a[i],max(maax,a[i]));
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        zsum+=a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
