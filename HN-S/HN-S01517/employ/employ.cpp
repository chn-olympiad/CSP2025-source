#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],p[505],tg[505],dp[505][505],jie[505];
string s;
void solve1(){
    cin>>s,s=' '+s;int ans=0;
    for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
    do{
        int num=0,l=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||l>=c[p[i]])l++;
            else num++,l=0;
        }
        if(num>=m)ans++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
}
void solve2(){
    int f=1,ans=0;
    cin>>s,s=' '+s;
    for(int i=1;i<=n;i++){cin>>c[i];if(c[i]==0)f=0;}
    for(int i=1;i<=n;i++)if(s[i]=='0')f=0;
    if(f){
        ans++;
        for(int i=2;i<=n;i++)ans=ans*i%mod;
    }
    cout<<ans<<'\n';
}
void solve3(){
    jie[0]=jie[1]=1;for(int i=2;i<=n;i++)jie[i]=jie[i-1]*i%mod;
    cin>>s,s=' '+s;int num=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')num++;
        cin>>c[i],tg[c[i]]++;
    }
    for(int i=1;i<=n;i++)tg[i]+=tg[i-1];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=num;j++)dp[i][j]=dp[i-1][j];
        if(s[i]=='1'){
            for(int j=1;j<=num;j++)dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(tg[i-1]-j+1))%mod;
        }
    }
    cout<<(jie[n]-dp[n][num]*jie[n-num]%mod+mod)%mod;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    if(n<=10)solve1();
    else if(n==m)solve2();
    else if(m==1)solve3();
    return 0;
}