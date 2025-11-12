#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int c[505];
int a[505];
int ans=0;
string s;
ll res=1;
int n,m;
void dg(int dep){
    if(dep==n+1){
        int cnt[505];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
            if(cnt[a[i]]>=2){
                return;
            }
        }
        int ct=0;
        int ly=0;
        for(int i=1;i<=n;i++){
            if(ct>=c[a[i]]){
                return;
            }
            if(s[i-1]=='0'){
                ct++;
            }else{
                ly++;
            }
        }
        if(ly>=m){
            ans++;
        }
        ans%=mod;
        return;
    }
    for(a[dep]=1;a[dep]<=n;a[dep]++){
        dg(dep+1);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int flag=1;
    for(int i=0;i<n;i++){
        if(s[i]!=1){
            flag=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        res=(res*i)%mod;
    }
    if(flag==1){
        cout<<res<<endl;
        return 0;
    }
    dg(1);
    cout<<ans<<endl;
    return 0;
}
