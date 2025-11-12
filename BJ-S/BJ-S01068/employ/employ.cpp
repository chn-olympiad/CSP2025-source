#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int c[N];
bool b[N];
int p[N];
string s;
const int mod=998244353;
long long ans=0;
void dfs(int x,int jv){
    if(jv>n-m) return;
    if(x==n+1){
        //cout<<"!";
        ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            //cout<<i<<" ";
            if((s[x-1]=='1')&&(jv<c[i])) dfs(x+1,jv);
            else dfs(x+1,jv+1);
            b[i]=0;
            //cout<<i<<" ";
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    int k=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) k=1;
    }
    if(n==m){
        for(int i=0;i<s.size();i++) if(s[i]=='0') k=1;
        if(k==1) cout<<0<<endl;
        else{
            ans=1;
            for(long long i=n;i>0;i--) {
                ans=ans*i;
                ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
    if(n<=10){
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}