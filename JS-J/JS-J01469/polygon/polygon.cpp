//nry
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void fileopen(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int a[500003],n;
namespace sub10{
    bool check(){return n<=20;}
    //int dp[503][503][503];
    int dfs(int now,int sum,int mx){
        //cerr<<"dfs("<<now<<","<<sum<<","<<mx<<")\n";
        if(now==n+1)return (int)(sum>2*mx);
        int res=0;
        (res+=dfs(now+1,sum+a[now],max(mx,a[now])))%=mod;
        (res+=dfs(now+1,sum,mx))%=mod;
        return res;
    }
    void solve(){
        //memset(dp,-1,sizeof(dp));
        cout<<dfs(1,0,0);
    }
}
namespace sub15_20{
    bool check(){
        int i;
        for(i=1;i<=n;i++)if(a[i]!=1)return false;
        return true;
    }
    int fpow(int a,int b){
        if(b==0)return 1;
        int x=fpow(a,b>>1);
        if(b&1)return x*x%mod*a%mod;
        return x*x%mod;
    }
    void solve(){
        cout<<(fpow(2,n)-n*(n-1)/2%mod-n-1+2*mod)%mod;
    }
}
namespace sub11_14{
    bool check(){
        int i;
        for(i=1;i<=n;i++)if(a[i]>100)return false;
        return n<=500;
    }
    int dp[503][207][107];
    int dfs(int now,int sum,int mx){
        if(now==n+1)return (int)(sum>2*mx);
        int &res=dp[now][sum][mx];
        if(res!=-1)return res;
        res=0;
        (res+=dfs(now+1,min(201ll,sum+a[now]),max(mx,a[now])))%=mod;
        (res+=dfs(now+1,sum,mx))%=mod;
        return res;
    }
    void solve(){
        memset(dp,-1,sizeof(dp));
        cout<<dfs(1,0,0);
    }
}
signed main(){
    fileopen("polygon");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    if(sub10::check()){
        sub10::solve();
        exit(0);
    }
    if(sub15_20::check()){
        sub15_20::solve();
        exit(0);
    }
    if(sub11_14::check()){
        sub11_14::solve();
        exit(0);
    }
    return 0;
}
//2012
/*
10:19 暴搜剪枝题！（）
10:26 写了一个68pts记忆化搜索，好像出了点问题？
10:33 喜报：记搜假了
10:36 临时改成了普通搜索，期望40 QAQ
10:48 写了ai=1的性质并通过对拍，期望来到64pts
10:55 记搜死灰复燃，将sum对201取min就能过11~14，期望得分80pts
*/
