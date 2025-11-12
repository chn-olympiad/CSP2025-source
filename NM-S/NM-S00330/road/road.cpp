#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10000][10000],b[100000],ans=100000000,vis[110000],mon[10000][10000];
void f(int r,int q){
    int flag=0;
    for (int i=1;i<=n;i++){
        if (vis[i]==0){
        flag=1;
        break;
        }
    }
    if (flag==0){
        ans=min(ans,q);
        return;
    }
    for (int i=1;i<=r[b];i++){
        if (vis[a[r][i]]==0){
            vis[a[r][i]]==1;
            f(a[r][i],q+mon[r][a[r][i]]);
            vis[a[r][i]]==0;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int h,j,moo;
        cin>>h>>j>>moo;
        b[h]++;
        b[j]++;
        a[h][b[h]]=j;
        a[j][b[j]]=h;
        mon[h][j]=moo;
        mon[j][h]=moo;
    }
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            vis[j]=0;
        }
        f(i,0);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

