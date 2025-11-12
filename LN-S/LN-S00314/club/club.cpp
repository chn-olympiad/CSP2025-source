#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
#define int long long
int t,n;
int a[N][4],res,aa,bb,cc;
void dfs(int x,int y){
    if(x==n){
        res=max(res,y);
        return;
    }
    if(aa+1<=n/2){
        aa++;
        dfs(x+1,y+a[x+1][1]);
        aa--;
    }
    if(bb+1<=n/2){
        bb++;
        dfs(x+1,y+a[x+1][2]);
        bb--;
    }
    if(cc+1<=n/2){
        cc++;
        dfs(x+1,y+a[x+1][3]);
        cc--;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        res=aa=bb=cc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(0,0);
        cout<<res<<"\n";
    }
    return 0;
}
