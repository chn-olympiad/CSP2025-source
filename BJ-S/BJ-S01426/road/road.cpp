#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=10025,M=2000006,debug=0;
int n,m,k,c[15],a[15][N];
int lst[N/10][N/10],cho;
int f[N];
long long ans=100000000000000000ll;
int find(int x){
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}
struct edge{
    int u,v,w;
    bool operator<(const edge& o)const{
        return w<o.w;
    }
}e[M/2],e1[M];
bool p1=1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
        if(e[i].v<=1000&&lst[e[i].u][e[i].v]){
            e[lst[e[i].u][e[i].v]].w=min(e[lst[e[i].u][e[i].v]].w,e[i].w);
            --m,--i;
        }
    }
    for(int j=0;j<k;j++){
        cin>>c[j];
        if(!c[j])cho|=(1<<j);
        else p1=0;
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    for(int now=0;now<(1<<k);now++){
        if(p1)now=(1<<k)-1;
        if((cho&now)!=cho)continue;
        long long sum=0;
        int cnt=0;
        for(int j=0;j<k;j++){
            if(now&(1<<j)){
                sum+=c[j];
                ++cnt;
                for(int i=1;i<=n;i++){
                    e1[m+(cnt-1)*n+i].u=i;
                    e1[m+(cnt-1)*n+i].v=n+cnt;
                    e1[m+(cnt-1)*n+i].w=a[j][i];
                }
            }
        }
        for(int i=m;i;i--)e1[i]=e[i];
        sort(e1+1,e1+m+cnt*n+1);
        for(int i=1;i<=n+cnt;i++)f[i]=i;
        for(int i=1;i<=m+cnt*n;i++){
            if(find(e1[i].u)!=find(e1[i].v)){
                sum+=e1[i].w;
                f[find(e1[i].u)]=find(e1[i].v);
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    if(debug){
        cout<<"我常常追忆过去。\n";
        cout<<"生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。\n";
        cout<<"云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。";
        cout<<"追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的好，那恰到好处的朦胧，才能满足我对美的苛求。\n";
        cout<<"追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。";
        cout<<"曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己，感受尽可能多的甜蜜。";
        cout<<"美好的时光曾流过我的身体，我便心满意足。\n";
        cout<<"过去已经凝固，我带着回忆向前，只是时常疏于保管，回忆也在改变着各自的形态。这给我的追忆旅程带来些许挑战。\n";
        cout<<"我该在哪里停留？我问我自己。\n";
    }
    return 0;
}