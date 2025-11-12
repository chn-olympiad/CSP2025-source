#include<bits/stdc++.h>
using namespace std;
int n,q;
int tot=1,chd[5000010][27],rt[5000010];
int cnt=0,son[5000010][27],fail[5000010],f[5000010];
vector<int>p1,p2;
string s1,s2;
void ins(int &rt){
    if(!rt)rt=++cnt;
    int now=rt;
    for(int c:p1){
        if(!son[now][c])son[now][c]=++cnt;
        now=son[now][c];
    }
    f[now]++;
}
void add(){
    int now=1;
    for(int c:p2){
        if(!chd[now][c])chd[now][c]=++tot;
        now=chd[now][c];
    }
    ins(rt[now]);
}
queue<int>que;
vector<int>e[5000010];
void dfs(int now){
    for(int to:e[now]){
        f[to]+=f[now];
        dfs(to);
    }
}
void build(int rt){
    for(int i=0;i<=26;i++)
        if(son[rt][i]){
            fail[son[rt][i]]=rt;
            que.push(son[rt][i]);
        }else son[rt][i]=rt;
    while(que.size()){
        int now=que.front();que.pop();
        e[fail[now]].push_back(now);
        for(int i=0;i<=26;i++)
            if(son[now][i]){
                fail[son[now][i]]=son[fail[now]][i];
                que.push(son[now][i]);
            }else
                son[now][i]=son[fail[now]][i];
    }
    dfs(rt);
}
int solve(){
    int res=0,now=1;
    for(int c:p2)now=chd[now][c];
    if(!now)return 0;
    now=rt[now];
    for(int c:p1){
        res+=f[now];
        now=son[now][c];
    }
    res+=f[now];
    return res;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int m=s1.size();
        s1=' '+s1,s2=' '+s2;
        int Min=m+1,Max=0;
        for(int j=1;j<=m;j++)
            if(s1[j]!=s2[j])
                Min=min(Min,j),
                Max=max(Max,j);
        if(Min>Max)continue;
        p1.clear(),p2.clear();
        for(int i=1;i<Min;i++)p1.push_back(s1[i]-'a');p1.push_back(26);
        for(int i=Max+1;i<=m;i++)p1.push_back(s1[i]-'a');
        for(int i=Min;i<=Max;i++)p2.push_back(s1[i]-'a');
        for(int i=Min;i<=Max;i++)p2.push_back(s2[i]-'a');
        add();
    }
    for(int i=1;i<=tot;i++)
        if(rt[i])
            build(rt[i]);
    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        int m=s1.size();
        s1=' '+s1,s2=' '+s2;
        int Min=m+1,Max=0;
        for(int j=1;j<=m;j++)
            if(s1[j]!=s2[j])
                Min=min(Min,j),
                Max=max(Max,j);
        p1.clear(),p2.clear();
        for(int i=1;i<Min;i++)p1.push_back(s1[i]-'a');p1.push_back(26);
        for(int i=Max+1;i<=m;i++)p1.push_back(s1[i]-'a');
        for(int i=Min;i<=Max;i++)p2.push_back(s1[i]-'a');
        for(int i=Min;i<=Max;i++)p2.push_back(s2[i]-'a');
        cout<<solve()<<'\n';
    }
    return 0;
}