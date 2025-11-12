#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=100005;
inline int read(){
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
int n,siz[4];
struct st{int id,w;}a[N][4];
inline bool cmp(st x,st y){return x.w>y.w;}
ll ans;
struct stt{
    int id,j,w;
    bool operator<(const stt &rhs)const{
        return w>rhs.w;
    }
};
priority_queue<stt> q[4];
inline void init(){
    ans=0;
    for(int i=1;i<=3;++i)siz[i]=0;
    for(int i=1;i<=3;++i)while(!q[i].empty())q[i].pop();
}
inline void solve(){
    n=read();
    init();
    for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)a[i][j].w=read(),a[i][j].id=j;
    for(int i=1;i<=n;++i){
        sort(a[i]+1,a[i]+4,cmp);
        for(int j=1;j<=3;++j){
            if(siz[a[i][j].id]+1<=n/2){
                siz[a[i][j].id]++;
                if(j<=2)q[a[i][j].id].push({i,j,a[i][j].w-a[i][j+1].w});
                else q[a[i][j].id].push({i,j,INF});
                ans+=a[i][j].w;
                break;
            }
            else{
                int w;
                if(j<=2)w=a[i][j].w-a[i][j+1].w;
                else w=INF;
                if(q[a[i][j].id].top().w<w){
                    int id=q[a[i][j].id].top().id,ppp=q[a[i][j].id].top().j;
                    ans-=q[a[i][j].id].top().w;
                    ans+=a[i][j].w;
                    q[a[i][j].id].pop();
                    q[a[i][j].id].push({i,j,w});
                    if(ppp+1==2)q[a[id][2].id].push({id,2,a[id][2].w-a[id][3].w});
                    else q[a[id][3].id].push({id,3,INF});
                    siz[a[id][ppp+1].id]++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;_=read();
    while(_--)solve();
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
