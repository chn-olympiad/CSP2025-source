#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,x[100005][100005];
struct rj{
    int a,b,c;
}sb[100005];
bool cmp(rj y,rj z){
    return y.c>z.c;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        cin>>sb[i].a>>sb[i].b>>sb[i].c;
    }
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=1+n;j++){
            cin>>x[i][j];
            x[i][n+2]+=x[i][j];
        }
    }
    sort(sb+1,sb+m+1,cmp);
    return 0;
}
