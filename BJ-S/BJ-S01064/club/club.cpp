#include <bits/stdc++.h>
using namespace std;
int A[205],B[205],C[205];
namespace prev11{
int dp[205][205][205];
int main(int n){
    memset(dp,0xcf,sizeof(dp));
    dp[1][1][0]=A[1];
    dp[1][0][1]=B[1];
    dp[1][0][0]=C[1];
    int ans=0xcfcfcfcf;
    for(int i=2;i<=n;i++){
        for(int a=0;(a<=i)&&(a*2)<=n;a++){
            for(int b=0;(b<=i-a)&&(b*2<=n);b++){
                int c=i-a-b;
                if(c*2>n)continue;
                if(a>0)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a-1][b]+A[i]);
                if(b>0)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b-1]+B[i]);
                if(c>0)dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b]+C[i]);
                if(i==n)ans=max(ans,dp[i][a][b]);
            }
        }
    }
    cout<<ans;
    return 0;
}
}
namespace oneclub{
int main(int n){
    sort(A+1,A+n+1);
    reverse(A+1,A+n+1);
    int ans=0;
    for(int i=1;i*2<=n;i++){
        ans+=A[i];
    }
    cout<<ans;
    return 0;
}
}
namespace twoclubs{
struct pers{
    int a,b;
    bool operator<(const pers x)const{
        return abs(a-b)>abs(x.a-x.b);
    }
}P[100005];
int main(int n){
    int a=0,b=0,ans=0;
    for(int i=1;i<=n;i++)P[i]={A[i],B[i]};
    sort(P+1,P+n+1);
    for(int i=1;i<=n;i++){
        pers p=P[i];
        if(p.a>p.b){
            if(a*2<n){
                a++;
                ans+=p.a;
            }else{
                b++;
                ans+=p.b;
            }
        }else{
            if(b*2<n){
                b++;
                ans+=p.b;
            }else{
                a++;
                ans+=p.a;
            }
        }
    }
    cout<<ans;
    return 0;
}
}
int solve(){
    int n;
    cin>>n;
    bool is1=1,is2=1;
    for(int i=1;i<=n;i++){
        cin>>A[i]>>B[i]>>C[i];
        if(B[i])is1=0;
        if(C[i])is1=0,is2=0;
    }
    int ans;
    if(is1)ans=oneclub::main(n);
    else if(is2)ans=twoclubs::main(n);
    else ans=prev11::main(n);
    cout<<'\n';
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int re=solve();
        if(re)return re;
    }
    return 0;
}