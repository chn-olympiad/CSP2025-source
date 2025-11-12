#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
long long ans;
void dfs(int x,int y,long long cnt){
    if(x==0){
        if(cnt>2*a[y-1]){
            ans++;
            ans%=MOD;
        }
        return;
    }
    for(int i=y;i<=n-x+1;i++){
        dfs(x-1,i+1,cnt+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int len=3;len<=n;len++){
        dfs(len,1,0);
    }
    cout<<ans;
    return 0;
}
