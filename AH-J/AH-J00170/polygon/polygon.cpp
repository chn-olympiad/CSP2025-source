#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[5005],kcnt;
void dfs(int x,int sum,int maxn,int cnt){
    if(x==n+1){
        if(sum>maxn*2&&cnt>2){
            kcnt++;
        }
        return ;
    }
    dfs(x+1,sum+s[x],max(maxn,s[x]),cnt+1);
    dfs(x+1,sum,maxn,cnt);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    dfs(1,0,0,0);
    cout<<kcnt;
    return 0;
}
