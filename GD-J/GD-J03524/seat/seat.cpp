#include<bits/stdc++.h>
using namespace std;
int n,m,nw;
struct F{
    int v,id;
}a[105];
bool cmp(F p,F q){
    return p.v>q.v;
}
int main(){
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].v,a[i].id=i;
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++)
        if(j&1) for(int i=1;i<=n;i++){
            ++nw;
            if(a[nw].id==1){
                cout<<j<<' '<<i;
                return 0;
            }
        }else for(int i=n;i>=1;i--){
            ++nw;
            if(a[nw].id==1){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    return 0;
}