#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Rof(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
using ll=long long;
using db=double;
using vi=vector<int>;
const int N=510;
const int mod=998244353;
int n,m,a[N];
int b[N],ans=0;
bool vis[N]={false};
string s;
void dfs(int nw){
    if(nw==n+1){
        // For(i,1,n){cout<<b[i]<<' ';}
        // cout<<'\n';
        int cnt=0;
        For(i,1,n){
            if(s[i]=='0'){
                cnt++;
            }
            else{
                if(cnt>=a[b[i]]){
                    cnt++;
                }
            }
        }
        if(n-cnt>=m){
            ans++;
        }
        return;
    }
    For(i,1,n){
        if(!vis[i]){
            vis[i]=1;
            b[nw]=i;
            dfs(nw+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    For(i,1,n){cin>>a[i];}
    // if(m==1){

    // }
    if(m==n){
        bool fl=1;
        For(i,1,n){
            if(s[i]=='0'){fl=0;}
            if(a[i]==0){fl=0;}
        }
        if(!fl){
            cout<<0<<'\n';
            return 0;
        }
        ll ans=1;
        For(i,1,n){ans=ans*i%mod;}
        cout<<ans<<'\n';
        return 0;
    }
    // bool fl=1;
    // For(i,1,n){if(s[i]=='0'){fl=0;}}
    // if(fl){//A
    // }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}