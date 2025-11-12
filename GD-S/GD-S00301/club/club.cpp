#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fu(i,x,y) for(int i=(x);i<(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int T,n,ans;vi G[5];
int main(){
    freopen("club.in","r",stdin);
    // freopen("club5.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        fo(i,0,2)G[i].clear();
        ans=0;
        fo(i,1,n){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            int w=max({x,y,z});ans+=w;
            if(x==w){
                G[0].pb(max(y,z)-x);
            }
            else if(y==w){
                G[1].pb(max(x,z)-y);
            }
            else{
                G[2].pb(max(y,x)-z);
            }
        }
        fo(i,0,2){
            int ln=G[i].size();
            // printf("%d\n",ln);
            if(ln>n/2){
                sort(G[i].begin(),G[i].end(),[&](int x,int y){return x>y;});
                // fu(j,0,ln)printf("%d ",G[i][j]);puts("");
                fo(j,1,ln-n/2)ans+=G[i][j-1];
            }
        }
        printf("%d\n",ans);
    }
}