#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int T,n,ans,a[N][3],siz[3],q[3][N];

int mmx(int x){
    int mx=a[x][0],mmx=0;
    if(mx<a[x][1])mmx=mx,mx=a[x][1];
    else if(mmx<a[x][1])mmx=a[x][1];
    if(mx<a[x][2])mmx=mx,mx=a[x][2];
    else if(mmx<a[x][2])mmx=a[x][2];
    return mmx;
}

void work(int id){
    sort(q[id]+1,q[id]+siz[id]+1,[&](int x,int y){return a[x][id]-mmx(x)<a[y][id]-mmx(y);});
    for(int i=1;i<=siz[id]-n/2;i++)ans=ans-a[q[id][i]][id]+mmx(q[id][i]);
}

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    siz[0]=siz[1]=siz[2]=ans=0;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<3;j++)if(a[i][j]>a[i][tmp])tmp=j;
        ans+=a[i][tmp],q[tmp][++siz[tmp]]=i;
    }
    for(int i=0;i<3;i++)if(siz[i]>n/2)work(i);
    printf("%d\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}