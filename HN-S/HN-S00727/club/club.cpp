#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
using namespace std;
const int MAXN=2e5+10;
int a[MAXN][3],id[MAXN][3];
int n;
int t[5],ans;
void solve(int x){
    priority_queue<int>q;
    for(int i=1;i<=n;i++){
        if(id[i][0]==x) {
            q.push(-a[i][id[i][0]]+a[i][id[i][1]]);
        }
    }
    int tmp=t[x]-(n/2);
    while(1){
        tmp--;
        ans+=q.top();q.pop();
        if(!tmp) break;
    }
    while(q.size()) q.pop();
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int T;cin>>T;
    while(T--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++){
            priority_queue<pii>q;
            for(int j=0;j<3;j++) {
                cin>>a[i][j];q.push(mk(a[i][j],j));
            }int tmp=0;
            while(q.size()){
                pii tp=q.top();q.pop();
                id[i][tmp++]=tp.second;
            }
            t[id[i][0]]++;ans+=a[i][id[i][0]];
        }
        if(t[0]<=n/2&&t[1]<=n/2&&t[2]<=n/2){
            cout<<ans<<'\n';
        }
        else{
            if(t[0]>n/2) solve(0);
            else if(t[1]>n/2) solve(1);
            else solve(2);cout<<ans<<'\n';
        }
        for(int i=0;i<3;i++) t[i]=0;
    }
    return 0;
}