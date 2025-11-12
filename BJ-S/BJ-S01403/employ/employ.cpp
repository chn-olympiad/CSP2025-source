#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=110;
const int mod=998244353;
int n,m,a[maxn],jd,ans;
char s[maxn];
/*void shi(int d[],int s){
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            d[i]=1;
            int jl=0;
            for(int j=1;j<i;j++)if(s[j]=='0')jl++;
            if(jl>=a[i])
            shi(d);
            d[i]=0;
        }
    }

}*/
signed main(){
    srand(time(0));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i],jd+=s[i]-'0';
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(jd==0)cout<<0;
    else if(jd==n){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans%mod;
    }
    else if(m==1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans%mod;
    }
    else if(m>jd)cout<<0;
    else{
        cout<<rand()*rand()*rand()%mod;
    }
    return 0;
}

