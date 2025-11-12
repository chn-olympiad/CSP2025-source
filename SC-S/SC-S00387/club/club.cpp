#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N][4];
struct club{
    int x,y;
};
vector<club>g[4];
bool cmp(club p,club q){
    return p.y<q.y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j]);
        }
        for(int i=1;i<=n;i++){
            int x=0,x1=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>a[i][x])x1=x,x=j;
                else if(a[i][j]>a[i][x1])x1=j;
            }
            g[x].push_back({a[i][x],a[i][x]-a[i][x1]});
        }
        long long ans=0;
        for(int i=1;i<=3;i++){
            for(club j:g[i]){
                ans+=j.x;
            }
            if((int)g[i].size()>n/2){
                sort(g[i].begin(),g[i].end(),cmp);
                for(int j=0;j<(int)g[i].size()-n/2;j++){
                    ans-=g[i][j].y;
                }
            }
        }
        printf("%lld\n",ans);
        for(int i=1;i<=3;i++)g[i].clear();
    }

    return 0;
}