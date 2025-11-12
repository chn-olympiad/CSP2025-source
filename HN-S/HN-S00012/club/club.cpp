#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,a[maxn][3],stk[3][maxn],top[3],ord[maxn][3],d[maxn];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            ord[i][j]=j;
        }
        sort(ord[i],ord[i]+3,[&](int x,int y){return a[i][x]<a[i][y];});
        stk[ord[i][2]][++top[ord[i][2]]]=i; d[i]=ord[i][2];
        // cerr<<ord[i][2]<<' ';
    }
    int pl=-1;
    for(int i=0;i<3;i++){
        if(top[i]>n/2) pl=i;
    }
    if(pl==-1){
        int ans=0;
        for(int i=1;i<=n;i++) ans+=a[i][d[i]];
        cout<<ans<<'\n';
        return ;
    }
    sort(stk[pl]+1,stk[pl]+top[pl]+1,[&](int x,int y){return a[x][ord[x][2]]-a[x][ord[x][1]]<a[y][ord[y][2]]-a[y][ord[y][1]];});
    for(int i=1;i<=top[pl]-n/2;i++) d[stk[pl][i]]=ord[stk[pl][i]][1];
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i][d[i]];
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _T;cin>>_T;while(_T--){ solve();top[0]=top[1]=top[2]=0;}
    return 0;
}