#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
bool flag=1;
const int mod=998244353;
long long ans;
bool vis[505];
string s;
long long suan(long long n){
    if(n==1) return 1;
    else return n*suan(n-1);
}
void dfs(int pos,int gone){
    // cout<<1<<endl;
    // if(pos==0) cout<<gone<<endl;
    // if(pos==1){
    //     // cout<<gone<<endl;
    // }
    if(pos==n){
        // for(int i:vec){
        //     cout<<i<<' ';
        // }
        // cout<<gone<<' ';
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     if(vis[i]) cout<<i<<' ';
        // }
        // cout<<endl;
        // cout<<n<<' '<<gone<<endl;
        if((n-gone)>=m) {
            // cout<<"ture"<<endl;
            ans++;
        }
        // else{
        //     cout<<endl;
        // }
        ans%=mod;
        return ;
    }
    for(int i=0;i<n;i++){
        
        // cout<<i<<' ';
        if(!vis[i]){
            // if(pos==n-1){
            //     cout<<gone;
            // }
            // cout<<s[i];
            if(s[i]=='1'&&c[i]>gone){
                vis[i]=1;
                dfs(pos+1,gone);
                vis[i]=0;
            }
            else{
                // cout<<c[i]<<'<'<<gone<<' '<<s[i]<<endl;
                vis[i]=1;
                // cout<<pos+1<<' '<<gone+1<<endl;
                dfs(pos+1,gone+1);
                vis[i]=0;
            }
            
        }
    }
    // cout<<endl;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    // cout<<n<<endl;
    int x=n;
    for(int i=0;i<x;i++){
        cin>>c[i];
        // if(c[i]==0) n--;
    }
    for(char c:s){
        if(c!='1'){
            flag=0;
            break;
        }
    }
    if(flag){
        // cout<<n<<endl;
        cout<<suan(n)%mod<<endl;
        return 0;
    }
    else{
        // cout<<0<<endl;
        dfs(0,0);
        cout<<ans-1<<endl;
    }
    return 0;
}