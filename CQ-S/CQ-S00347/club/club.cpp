//14:57 100
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
using ll=long long;
const int N=1e5+5;
int T,n,ans;
PII a[N][3];
struct node{
    int pos,v,now;
    friend bool operator<(node x,node y){return x.v>y.v;}
};
priority_queue<node>q[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    double st=clock();
    cin>>T;
    while(T--){
        cin>>n;ans=0;
        for(int i=0;i<3;i++){
            while(!q[i].empty())    q[i].pop();
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++)    cin>>a[i][j].fi,a[i][j].se=j;
            if(a[i][0].fi<a[i][1].fi)   swap(a[i][0],a[i][1]);
            if(a[i][1].fi<a[i][2].fi)   swap(a[i][1],a[i][2]);
            if(a[i][0].fi<a[i][1].fi)   swap(a[i][0],a[i][1]);
            ans+=a[i][0].fi;q[a[i][0].se].push({i,a[i][0].fi-a[i][1].fi,0});
            // for(int j=0;j<3;j++)    cerr<<i<<" "<<j<<" "<<a[i][j].fi<<" "<<a[i][j].se<<"\n";
        }
        while(1){
            for(int i=0;i<3;i++){
                if(q[i].size()>n/2){
                    // cerr<<i<<" ";
                    node tmp=q[i].top();q[i].pop();
                    ans-=tmp.v;
                    if(tmp.now==0)  q[a[tmp.pos][1].se].push({tmp.pos,a[tmp.pos][1].fi-a[tmp.pos][2].fi,1});
                    else    q[a[tmp.pos][2].se].push({tmp.pos,0x3f3f3f3f,2});
                    goto nxt;
                }
            }
            break;
            nxt:;
        }
        cout<<ans<<"\n";
    }
    cerr<<fixed<<setprecision(6)<<(clock()-st)/CLOCKS_PER_SEC<<"\n";
}