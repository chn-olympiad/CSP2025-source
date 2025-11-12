#include<unordered_map>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
constexpr int N=5000006,debug=0;
bool flag[N];
int n,q,id[N],trie[N][30],fail[N],du[N],tot,I;
vector<int>v[N][2];
int insert(string s){
    int x=0;
    for(char i:s){
        i-='a';
        if(!trie[x][i])trie[x][i]=++tot;
        x=trie[x][i];
    }
    flag[x]=1;
    return x;
}
void bfs(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(trie[0][i])q.push(trie[0][i]);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(!trie[x][i]){
                trie[x][i]=trie[fail[x]][i];
                continue;
            }
            fail[trie[x][i]]=trie[fail[x]][i];
            ++du[trie[fail[x]][i]];
            q.push(trie[x][i]);
        }
    }
}
void topo(){
    queue<int>q;
    for(int i=1;i<=tot;i++){
        if(!du[i])q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        unordered_map<int,bool>vis;
        for(int i:v[x][I])vis[i]=1;
        v[x][I].clear();
        if(flag[x]){
            for(auto i:vis){
                v[x][I].push_back(i.first);
            }
        }
        if(fail[x]){
            q.push(fail[x]);
            for(int i:v[fail[x]][I])vis[i]=1;
            v[fail[x]][I].clear();
            for(auto i:vis){
                v[fail[x]][I].push_back(i.first);
            }
        }
    }
}
string s[2],t[200005][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        s[0]+=s1,s[1]+=s2;
        s[0].push_back('*'),s[1].push_back('*');
    }
    for(int j=1;j<=q;j++){
        string s1,s2;
        cin>>s1>>s2;
        int l=N,r=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(l==N)l=i;
                r=i;
            }
        }
        for(int i=l;i<=r;i++){
            t[j][0].push_back(s1[i]);
            t[j][1].push_back(s2[i]);
        }
    }
    if(debug)cout<<s[0]<<'\n';
    for(int i=1;i<=q;i++){
        if(debug)cout<<t[i][0]<<'\n';
        id[i]=insert(t[i][0]);
    }
    bfs();
    for(int i=0,j=0,now=1;i<s[0].size();i++){
        if(s[0][i]=='*')j=0,++now;
        else j=trie[j][s[0][i]-'a'];
        if(j)v[j][0].push_back(now);
    }
    topo();
    tot=0;
    memset(trie,0,sizeof(trie));
    memset(fail,0,sizeof(fail));
    memset(du,0,sizeof(du));
    memset(flag,0,sizeof(flag));
    ++I;
    if(debug)cout<<s[1]<<'\n';
    for(int i=1;i<=q;i++){
        if(debug)cout<<t[i][1]<<'\n';
        id[i]=insert(t[i][1]);
    }
    bfs();
    for(int i=0,j=0,now=1;i<s[1].size();i++){
        if(s[1][i]=='*')j=0,++now;
        else j=trie[j][s[1][i]-'a'];
        if(j)v[j][1].push_back(now);
    }
    topo();
    for(int i=1;i<=q;i++){
        unordered_map<int,short>cnt;
        for(int j:v[id[i]][0])cnt[j]++;
        for(int j:v[id[i]][1])cnt[j]++;
        int ans=0;
        for(auto j:cnt){
            if(j.second==2)++ans;
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