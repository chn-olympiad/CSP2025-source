#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[4][100010],vos[4];
int ans=-1;
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
void dfs(int x,int sum,int n){
    int f=n/2;
    if(vos[1]>f||vos[2]>f||vos[3]>f){
        return ;
    }
    if(x>n){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        vos[i]++;
        dfs(x+1,sum+a[i][x],n);
        vos[i]--;
    }
    return ;
}
void solve(){
    int n=read();
    for(int i=1;i<=n;i++){
        int a1=read(),a2=read(),a3=read();
        a[1][i]=a1,a[2][i]=a2,a[3][i]=a3;
    }
    dfs(1,0,n);
    cout<<ans<<'\n';
    for(int i=0;i<=10009;i++){
        a[0][i]=a[1][i]=a[2][i]=a[3][i]=0;
    }
    vos[0]=vos[1]=vos[2]=vos[3]=ans=0;
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=read();
    while(t--){
        solve();
    }
    return 0;
}
