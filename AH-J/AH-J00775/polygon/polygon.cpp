#include<bits/stdc++.h>
using namespace std;
long long n,a[5009],cnt,ans[5009],sum;
bool check(long long cur){
    return sum>ans[cur]*2;
}
void dfs(long long cur,long long pre){
    if(cur>=3&&check(cur-1)){cnt++;cnt%=998244353;}
    for(long long i=pre+1;i<=n;i++){
        sum+=a[i];
        ans[cur]=a[i];
        dfs(cur+1,i);
        sum-=a[i];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    dfs(1,0);
    cout<<cnt;
    return 0;
}

