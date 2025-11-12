#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int N=5000+5;
int a[N],js[N];
int n;
long long ans;
void dfs1(long long tot,int maxn,long long num,int t,bool tag){
    if(tot+a[n]>maxn*2&&num>=3&&tag==0&&t<n/2){
        int64_t aaa=1<<(n-t+1);
        aaa%=Mod;
        ans=ans+aaa;
        ans%=Mod;
        return;
    }
    if(tot>maxn*2&&num>=3&&tag==0){ans++;ans%=Mod;}
    if(t==n+1)return;
    dfs1(tot+a[t],max(maxn,a[t]),num+1,t+1,0);
    dfs1(tot,maxn,num,t+1,1);
}
void dfs2(long long tot,int maxn,long long num,int t,bool tag){
    if(tot>maxn*2&&num>=3&&tag==0){ans++;ans%=Mod;}
    if(t==n+1)return;
    dfs2(tot+a[t],max(maxn,a[t]),num+1,t+1,0);
    dfs2(tot,maxn,num,t+1,1);
}
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        js[i]=js[i-1]+a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n<=50)dfs2(0,0,0,1,0);
    else dfs1(0,0,0,1,0);
    cout<<ans%Mod;
    return 0;
}
