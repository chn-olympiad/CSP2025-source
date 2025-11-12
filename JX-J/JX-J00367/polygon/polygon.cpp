#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[5005];
bool useed[5005];
int n,ans=0;
void dfs(int x,int now){
    if(x==0){
        int maxs;
        for(int i=n;i>=1;i--){
            if(useed[i]){
                maxs=a[i];
                break;
            }
        }
        if(now>maxs*2)ans++;
        ans%=998244353;
        return;
    }
    for(int i=1;i>=0;i--){
        useed[x]=i;
        dfs(x-1,now+a[x]*i);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(n,0);
    cout<<ans;
    return 0;
}
