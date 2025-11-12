#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
const int P=998244353;
bool flag=true;
int n,res,a[N],p[N];
void dfs(int dep,int cnt,bool f){
    if(f) p[cnt]=a[dep-1];
    if(dep>n){
        if(cnt>=3){
            int tot=0,maxn=-1e9;
            for(int i=1;i<=cnt;i++){
                tot+=p[i];
                maxn=max(maxn,p[i]);
            }
            if(tot>2*maxn) res=(res+1)%P;
        }
        return;
    }
    dfs(dep+1,cnt+1,true);
    dfs(dep+1,cnt,false);
}
void t_dfs(int dep,int cnt){
    if(dep>n){
        if(cnt>=3) res=(res+1)%P;
        return;
    }
    t_dfs(dep+1,cnt+1);
    t_dfs(dep+1,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=false;
    }
    if(flag){
        t_dfs(1,0);
        cout<<res%P<<"\n";
        return 0;
    }
    dfs(1,0,false);
    cout<<res%P<<"\n";
    return 0;
}