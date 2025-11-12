#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int N = 5010;
int n,ans,a[N],book[N],f[N][N][2],num[N][N],Max[N][N];
//f[i][j]=f[now][choose]
//f[i][j][0]=max(f[i][j][0],max(f[k][j][0],f[k][j][1]));   //k<i
//f[i][j][1]=max(f[i][j][1],max(max(f[k][j-1][0],f[k][j-1][1])*(num[k][j-1]+a[i]>max(Max[k][j-1],a[i])*2),max(f[k][j][0],f[k][j][1])*(num[k][j]+a[i]>max(Max[k][j],a[i])*2));    //k<i
void dfs(int now){
    if(now>n){
        int sum=0,maxn=0;
        for(int i=1;i<=n;++i){
            if(!book[i]) sum+=a[i],maxn=max(maxn,a[i]);
        }
        if(sum>maxn*2) ans++;
        if(ans>=mod) ans-=mod;
        return ;
    }
    dfs(now+1);
    book[now]=1;
    dfs(now+1);
    book[now]=0;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(n<=25){
        dfs(1);
        cout<<ans;
    }
    else cout<<0;
    return 0;
}