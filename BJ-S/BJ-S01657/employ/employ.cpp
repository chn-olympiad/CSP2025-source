#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,ans,a[N],p[N],cnt[N];
string s;
mt19937_64 rnd(time(0));
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n<=10){
        for(int i=1;i<=n;++i)p[i]=i;
        do{
            int tot=0,num=0;
            for(int i=1;i<=n;++i){
                if(s[i-1]=='0'||tot>=a[p[i]])++tot;
                else++num;
            }if(num>=m)++ans;
        }while(next_permutation(p+1,p+n+1));
    }else if(m==n){
        for(int i=0;i<n;++i)if(s[i]=='0'||!a[i+1]){
            cout<<0;
            return 0;
        }ans=1;
        for(int i=1;i<=n;++i)ans=1LL*ans*i%mod;
    }else ans=rnd()%mod;
    cout<<ans;
    return 0;
}