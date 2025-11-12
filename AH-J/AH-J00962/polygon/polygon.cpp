#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[5005],cnt;
ll ans[5005];
void dfs(ll t,ll sum,ll maxn,ll num){
    if(sum+ans[n]-ans[t-1]<maxn*2) return ;
    if(t==n+1){
        if(sum>maxn*2&&num>=3){
            cnt++;
            cnt%=998244353;
        }
        return ;
    }
    dfs(t+1,sum+x[t],max(maxn,x[t]),num+1);
    dfs(t+1,sum,maxn,num);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x[i];
        ans[i]=ans[i-1]+x[i];
    }
    dfs(1,0,0,0);
    cnt%=998244353;
    cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


