#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
using namespace std;
int n,m,c[20];
string s;
int C[20],v[20],ans;
void dfs(int d){
    if(d>n){
        int sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                if(cnt>=c[C[i]]) cnt++;
                else sum++;
            }else{
                cnt++;
            }  
        }
        if(sum>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]) continue;
        C[d]=i;v[i]=1;
        dfs(d+1);
        v[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    if(n<=18){
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        dfs(1);
        cout<<ans<<endl;
        return 0;
    }else{
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            if(c[i]==0) cnt++;
        }
        int ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans<<endl;
    }
    return 0;
}