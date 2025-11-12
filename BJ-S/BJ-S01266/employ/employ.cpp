#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int Mod=998244353;
long long n,m;
string s;
long long len;
long long ss[N];
long long out[N];
long long c[N];
long long vis[N];
long long ans[N];
long long sum;
void dfs(long long pos){
    if(pos==n+1){
        bool flag=true;
        long long p=n;
        for(int i=1;i<=n;i++){
            if(out[i-1]>=c[ans[i]]||ss[i]==0){
                p-=1;
            }
        }
        if(p>=m){
           /* for(int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;*/
            sum=(sum+1)%Mod;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        vis[i]=1;
        ans[pos]=i;
        dfs(pos+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        ss[i+1]=s[i]-'0';
        if(ss[i+1]==0)out[i+1]=out[i]+1;
        else out[i+1]=out[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    /*for(int i=1;i<=n;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;*/
    dfs(1);
    cout<<sum;

    return 0;
}
