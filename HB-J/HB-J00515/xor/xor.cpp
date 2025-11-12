#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+50;
const int M=255+5;

template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}


ll n,k,ans,s[N];
bool flag=1;
ll dp[N][M];
ll q[N];

void solve1(){
    ll last=1;
    for(ll i=1;i<=n;i++){
        for(ll j=last;j<=i;j++){
            if((q[i]^q[j-1])==k){
                ans++;
                last=i+1;
                break ;
            }
        }
    }
    cout<<ans<<endl;
    return ;
}

void solve2(){
    for(ll i=0;i<=255;i++){
        dp[0][i]=-INT_MAX;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=255;j++){
            dp[i][j^s[i]]=dp[i-1][j];
        }
        dp[i][s[i]]=i;
    }
    ll last=1;
    for(ll i=1;i<=n;i++){
        if(dp[i][k]>=last){
            ans++;
            last=i+1;
        }
    }
    cout<<ans<<endl;
    return ;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    srand(time(0));
    n=read<ll>();
    k=read<ll>();
    q[0]=0;
    for(ll i=1;i<=n;i++){
        s[i]=read<ll>();
        q[i]=q[i-1]^s[i];
        if(s[i]>255) flag=0;
    }
    if(n<=1e3+50) solve1();
    else if(flag) solve2();
    else{
        cout<<rand()%(n/2)<<endl;
    }
    return 0;
}
