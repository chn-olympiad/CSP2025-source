#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[500010],xxor[500010],cnt=0;
int dp[50000010][2];
bool f=true;
struct node{
    int l,r;
}b[10000010];
bool cmp(node x,node y){
    if(x.l!=y.l)
        return x.l<y.l;
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xxor[i]=(xxor[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if((xxor[j]^xxor[i-1])==k)
                b[++cnt]={i,j};
    sort(b+1,b+cnt+1,cmp);
    dp[0][0]=dp[0][1]=0;
    dp[1][0]=0,dp[1][1]=1;
    for(int i=2;i<=cnt;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        int j;
        for(j=i;j>=1;j--){
            if(b[j].r<b[i].l)
                break;
        }
        dp[i][1]=max(dp[j][0],dp[j][1])+1;
    }
    cout<<max(dp[cnt][0],dp[cnt][1]);
    return 0;
}
