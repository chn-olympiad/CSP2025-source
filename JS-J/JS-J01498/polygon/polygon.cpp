#include<bits/stdc++.h>
#define int long long
using namespace std;
#define MOD %998244353
int n,ans=0;
vector<int> a;
void dfs(int u,int sum,int maxn,int choice){
    if(u==n+1){
        if(sum>maxn*2&&choice>2) ans=(ans+1)MOD;
        return;
    }
    dfs(u+1,sum+a[u],max(maxn,a[u]),choice+1);
    dfs(u+1,sum,maxn,choice);
}
int qpow(int b){
    if(!b) return 1;
    int temp=qpow(b/2)MOD;
    temp*=temp;
    temp=temp MOD;
    if(b&1) temp<<=1;
    return temp MOD;
}
signed main(){
    #ifndef NOFREOPEN
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    #endif // NOFREOPEN
    bool flag=true;
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]&&i-1){
            flag=false;
        }
    }
    if(flag){
        ans=qpow(n)MOD;
        ans=(ans-1)MOD;
        ans=(ans-n)MOD;
        ans=(ans-((n*(n-1)/2)MOD))MOD;
        cout<<ans<<endl;
        exit(0);
    }
    dfs(1,0,INT_MIN,0);
    cout<<ans;
}
