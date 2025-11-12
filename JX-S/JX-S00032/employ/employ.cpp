#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,MOD=998244353;
int n,m,c[N],ans,pd[N],a[N];
string s;
void dfs(int k){
    if(k==n+1){
        int nx=0,sum=0;
        for(int i=1;i<=n;i++){
            if(nx>=c[a[i]]){
                nx++;
                continue;
            }
            if(s[i]-'0'==1) sum++;
            else nx++; 
        }
        if(sum>=m) ans++,ans%=MOD;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!pd[i]){
            pd[i]=1;
            a[k]=i;
            dfs(k+1);
            pd[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}