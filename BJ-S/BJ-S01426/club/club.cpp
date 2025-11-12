#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=100005,debug=0;
int T,n,I,a[N][3],p[N][4],to[N];
bool cmp(int i,int j){
    return a[I][i]>a[I][j];
}
struct node{
    int i,d;
    bool operator<(const node &o) const{
        return d>o.d;
    }
};
priority_queue<node>q[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            I=i,p[i][0]=0,p[i][1]=1,p[i][2]=2;
            sort(p[i],p[i]+3,cmp);
            q[p[i][0]].push({i,a[i][p[i][0]]-a[i][p[i][1]]});
        }
        while(q[0].size()>(n/2)){
            int x=q[0].top().i;
            q[0].pop();
            q[p[x][1]].push({x,0});
        }
        while(q[1].size()>(n/2)){
            int x=q[1].top().i;
            q[1].pop();
            q[p[x][1]].push({x,0});
        }
        while(q[2].size()>(n/2)){
            int x=q[2].top().i;
            q[2].pop();
            q[p[x][1]].push({x,0});
        }
        long long ans=0;
        while(!q[0].empty()){
            to[q[0].top().i]=0;
            ans+=a[q[0].top().i][0];
            q[0].pop();
        }
        while(!q[1].empty()){
            to[q[1].top().i]=1;
            ans+=a[q[1].top().i][1];
            q[1].pop();
        }
        while(!q[2].empty()){
            to[q[2].top().i]=2;
            ans+=a[q[2].top().i][2];
            q[2].pop();
        }
        cout<<ans<<'\n';
    }
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