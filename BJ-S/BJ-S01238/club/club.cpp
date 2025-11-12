#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N=1e5;
int n,ans;
ll a[N+5][5];
struct node{
    int a;
}b[N+5];
ll dp[2][101][101][101];
void case1(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int x=0;x<=(i,n/2);x++){
            for(int y=0;y<=min(n/2,i);y++){
                int z=i-x-y;
                if(z>i||z>n/2) continue;
                if(x>0) dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i-1)%2][x-1][y][z]+a[i][1]);
                if(y>0) dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i-1)%2][x][y-1][z]+a[i][2]);
                if(z>0) dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i-1)%2][x][y][z-1]+a[i][3]);
                if(i==n) ans=max(ans,dp[i%2][x][y][z]);
            }
        }
    }
    cout<<ans<<'\n';
    return ;
}
bool cmp(node x,node y){
    return x.a>y.a;
}
void caseA(void){
    for(int i=1;i<=n;i++){
        b[i].a=a[i][1];
    }
    sort(b+1,b+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=n/2;i++) ans+=b[i].a;
    cout<<ans;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof dp);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        if(n<=200) case1();
        else caseA();
    }
    return 0;
}
