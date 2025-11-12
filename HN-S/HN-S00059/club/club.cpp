#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace fisher{
const int N=1e5+5;
int T,n,ans,a[N][4];
struct node{
    int i,x,y;
    friend bool operator <(const node &x,const node &y){
        return a[x.i][x.x]-a[x.i][x.y]>a[y.i][y.x]-a[y.i][y.y];
        // return (a[x.i][x.x]!=a[y.i][y.x]?a[x.i][x.x]>a[y.i][y.x]:a[x.i][x.y]<a[y.i][y.y]);
    }
};
priority_queue <node> q[5];
node gmx(int i){
    int x=0,y=0;
    if(a[i][1]>a[i][x]) y=x,x=1;
    else if(a[i][1]>a[i][y]) y=1;
    if(a[i][2]>a[i][x]) y=x,x=2;
    else if(a[i][2]>a[i][y]) y=2;
    if(a[i][3]>a[i][x]) y=x,x=3;
    else if(a[i][3]>a[i][y]) y=3;
    return (node){i,x,y};
}
void change(node &x){
    node y=q[x.x].top();
    if(a[y.i][y.x]+a[x.i][x.y]<a[y.i][y.y]+a[x.i][x.x]){
        // cout<<x.i<<' '<<y.i<<'\n';
        q[x.x].pop();q[x.x].push(x);
        q[y.y].push((node){y.i,y.y,0});
    }
    else q[x.y].push((node){x.i,x.y,0});
}
signed ckt(){
    node x;
    for(cin>>T;T;T--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            x=gmx(i);
            if((int)q[x.x].size()*2==n){
                change(x);
                // cout<<i<<' ';
            }
            else q[x.x].push(x);
        }
        // cout<<'\n';
        for(int op=1;op<=3;op++) while(!q[op].empty()){
            x=q[op].top();q[op].pop();
            ans+=a[x.i][x.x];
        }
        cout<<ans<<'\n';
    }
    return 0;
}}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    return fisher::ckt();
}