#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
struct node{
    int m;
    int id;
}a[105];
bool cmp(node x,node y){
    if(x.m!=y.m) return x.m>y.m;
    return x.id<y.id;
}
int n,m,k=0;
node mp[15][15];
void dfs(int sx,int sy,int s){
    mp[sx][sy]=a[++k];
    if(a[k].id==1 || (sx==n && sy==m)) return;
    if((sx==n && s==1) || (sx==1 && s==-1))
        dfs(sx,sy+1,-s);
    else
        dfs(sx+s,sy,s);
}
int main(){
    IOS;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].m;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    dfs(1,1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j].id==1){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
