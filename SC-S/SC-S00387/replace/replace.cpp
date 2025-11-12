
#include<bits/stdc++.h>
using namespace std;
const int N=6e6+5;
string s1,s2;
int n,qu,tot;
int tr[N][27],fail[N],cnt[N];
vector<int>g[N];
queue<int>q;
void build(){
    for(int i=0;i<27;i++){
        if(tr[0][i])q.push(tr[0][i]);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<27;i++){
            int &p=tr[u][i];
            if(!p)p=tr[fail[u]][i];
            else fail[p]=tr[fail[u]][i],q.push(p);
        }
    }
}
string t;
void ins(){
    int u=0;
    for(int i=0;i<(int)t.size();i++){
        int to=t[i]-'a';
        if(!tr[u][to])tr[u][to]=++tot;
        u=tr[u][to];
    }
    cnt[u]++;
}
void dfs(int u){
    for(int v:g[u]){
        cnt[v]+=cnt[u];
        dfs(v);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // char a='{';
    // cout<<(char)(a-1);
    cin>>n>>qu;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        t.resize(0);
        int len=s1.size();
        int pre=0,suf=0;
        for(pre=0;pre<len;pre++){
            if(s1[pre]!=s2[pre])break;
        }
        for(suf=(int)len-1;suf>=0;suf--){
            if(s1[suf]!=s2[suf])break;
        }
        if(pre>suf)continue;
        if(pre>0){
            t+=s1.substr(0,pre);
        }
        t+='{',t+=s1.substr(pre,suf-pre+1),t+='{',t+=s2.substr(pre,suf-pre+1),t+='{';
        if(suf!=(int)len-1){
            t+=s1.substr(suf+1,len-1-suf);
        }
        // cout<<t<<endl;
        ins();
    }
    build();
    for(int i=1;i<=tot;i++)g[fail[i]].push_back(i);
    dfs(0);
    for(int _=1;_<=qu;_++){
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            puts("0");
            continue;
        }
        t.resize(0);
        int len=s1.size();
        int pre=0,suf=0;
        for(pre=0;pre<len;pre++){
            if(s1[pre]!=s2[pre])break;
        }
        for(suf=(int)len-1;suf>=0;suf--){
            if(s1[suf]!=s2[suf])break;
        }
        if(pre>suf)continue;
        if(pre>0){
            t+=s1.substr(0,pre);
        }
        t+='{',t+=s1.substr(pre,suf-pre+1),t+='{',t+=s2.substr(pre,suf-pre+1),t+='{';
        if(suf!=(int)len-1){
            t+=s1.substr(suf+1,len-1-suf);
        }
        // cout<<t<<endl;
        int u=0;
        int ans=0;
        for(int i=0;i<(int)t.size();i++){
            int to=t[i]-'a';
            u=tr[u][to];
            ans+=cnt[u];
        }
        printf("%d\n",ans);
    }

    return 0;
}