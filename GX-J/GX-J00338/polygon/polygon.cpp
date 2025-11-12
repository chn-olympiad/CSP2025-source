#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
using namespace std;
const int fet=5010;
int n,a[fet];

int ans;
bool vis[fet];
int sum;
int maxn=-inf,
t,lost[fet];
string mem;
map<string,bool> m;
int t_;
string lost_[fet];
void mod(){
    ans%=998,ans%=244,ans%=353;
}
string gu(int x){
    string res="";
    while(x){
        res+=(char)(x%10+'0');
        x/=10;
    }
    return res;
}
void dfs(int x){
    if(x>=3){
        if(sum>maxn*2&&!m[mem]) ans++,m[mem]=true;
        mod();
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=true; sum+=a[i];
        lost_[t++]=mem; mem+=gu(i);
        lost[t++]=maxn; maxn=max(maxn,a[i]);
        dfs(x+1);
        maxn=lost[t--];
        mem=lost_[t_--];
        vis[i]=false; sum-=a[i];
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0);
    cout<<ans;
    return 0;
}
