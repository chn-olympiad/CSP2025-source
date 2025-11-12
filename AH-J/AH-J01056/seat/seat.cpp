#include "bits/stdc++.h"
#define int long long
using namespace std;
priority_queue<int> q;
int g[15][15];
int n,m,a,t;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    t=a;
    q.push(a);
    for(int i=2;i<=n*m;i++){
        cin>>a;
        q.push(a);
    }
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                int u=q.top();
                g[i][j]=u;
                q.pop();
            }
        }else if(j%2==0){
            for(int i=n;i>=1;i--){
                int u=q.top();
                g[i][j]=u;
                q.pop();
            }
        }
    }

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(g[i][j]==t){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
