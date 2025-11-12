#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],m;
long long mod=998244353;
long long ans=0;
long long kk;
bool f=0;
string s;
bool vis[100005];
long long vvis[100050];
void dfs(long long d,long long sum,long long die){
    //cout<<die<<"\n";
    if(d>n){
        //ans=min(ans,sum);
            //cout<<sum<<"\n";
            if(sum>=m){
                    ans++;
                    //for(int i=1;i<=n;i++)cout<<vvis[i]<<" ";cout<<sum<<"\n";
            }
    ans%=mod;
    return;


    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vvis[d]=i;
            vis[i]=1;
            if(die>=a[i]||s[d]=='0'){
                    //cout<<"OO:"<<i<<"\n";
                dfs(d+1,sum,die+1);
            }else dfs(d+1,sum+1,die);
            vis[i]=0;
        }
    }
}
void ddfs(long long d,long long sum,long long die){
    //cout<<die<<"\n";
    if(d>n){
        //ans=min(ans,sum);
            //cout<<sum<<"\n";
            if(sum>=m){
                    ans++;
                    //for(int i=1;i<=n;i++)cout<<vvis[i]<<" ";cout<<sum<<"\n";
            }
    ans%=mod;
    return;


    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vvis[d]=i;
            vis[i]=1;
            if(die>=a[i]||s[d]=='0'){
                    continue;
                dfs(d+1,sum,die+1);

            }else dfs(d+1,sum+1,die);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s="i"+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)f=1;
    }

    if(n==m){
            if(f){
                cout<<0;
                return 0;
            }
        ddfs(1,0,0);
        cout<<ans;
        return 0;
    }dfs(1,0,0);
    cout<<ans;
    return 0;
}
