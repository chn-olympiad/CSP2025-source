#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 3000005
#define p 131
#define ull unsigned long long
#define pii pair<int,int>
#define fr first
#define se second
char ch;
struct node{int x,y,id;};
int n,q,ans[N];
int tr[M][26],tot,root[M],dfn[M],siz[M],dfc;
char s1[M],s2[M];
map<pair<ull,ull>,int> rt1,rt2;
vector<pii> d;
vector<node> add,qry;
void dfs(int u){
    siz[u]=1;
    dfn[u]=++dfc;
    for(int i=0;i<26;i++)if(tr[u][i])
        dfs(tr[u][i]),siz[u]+=siz[tr[u][i]];
}
namespace bit{
    int tr[M];
    void add(int x,int y){
        for(int i=x;i<=tot;i+=i&-i)tr[i]+=y;
    }
    int qry(int x){
        int ans=0;
        for(int i=x;i;i-=i&-i)ans+=tr[i];
        return ans;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);ch=getchar();
    for(int i=1;i<=n;i++){
        int len=0;
        while(ch<'a'||ch>'z')ch=getchar();
        while('a'<=ch&&ch<='z')s1[++len]=ch,ch=getchar();
        len=0;
        while(ch<'a'||ch>'z')ch=getchar();
        while('a'<=ch&&ch<='z')s2[++len]=ch,ch=getchar();
        int l=-1,r=-1;
        for(int i=1;i<=len;i++)if(s1[i]!=s2[i]){l=i;break;}
        for(int i=len;i;i--)if(s1[i]!=s2[i]){r=i;break;}
        if(l==-1)continue;
        ull h1=0,h2=0;
        for(int i=l;i<=r;i++){
            h1=h1*p+s1[i];
            h2=h2*p+s2[i];
        }
        if(!rt1[{h1,h2}]){
            rt1[{h1,h2}]=++tot;root[tot]=1;
            rt2[{h1,h2}]=++tot;root[tot]=1;
        }
        int r1=rt1[{h1,h2}];
        for(int i=l-1;i;i--){
            if(!tr[r1][s1[i]-'a'])tr[r1][s1[i]-'a']=++tot;
            r1=tr[r1][s1[i]-'a'];
        }
        int r2=rt2[{h1,h2}];
        for(int i=r+1;i<=len;i++){
            if(!tr[r2][s1[i]-'a'])tr[r2][s1[i]-'a']=++tot;
            r2=tr[r2][s1[i]-'a'];
        }
        d.push_back({r1,r2});
    }
    for(int i=1;i<=tot;i++)if(root[i])dfs(i);
    for(int i=1;i<=q;i++){
        int len1=0,len=0;
        while(ch<'a'||ch>'z')ch=getchar();
        while('a'<=ch&&ch<='z')s1[++len1]=ch,ch=getchar();
        while(ch<'a'||ch>'z')ch=getchar();
        while('a'<=ch&&ch<='z')s2[++len]=ch,ch=getchar();
        if(len!=len1)continue;
        int l=-1,r=-1;
        for(int i=1;i<=len;i++)if(s1[i]!=s2[i]){l=i;break;}
        for(int i=len;i;i--)if(s1[i]!=s2[i]){r=i;break;}
        ull h1=0,h2=0;
        for(int i=l;i<=r;i++){
            h1=h1*p+s1[i];
            h2=h2*p+s2[i];
        }
        if(!rt1[{h1,h2}])continue;
        int r1=rt1[{h1,h2}];
        for(int i=l-1;i;i--){
            if(!tr[r1][s1[i]-'a'])break;
            r1=tr[r1][s1[i]-'a'];
        }
        int r2=rt2[{h1,h2}];
        for(int i=r+1;i<=len;i++){
            if(!tr[r2][s1[i]-'a'])break;
            r2=tr[r2][s1[i]-'a'];
        }
        qry.push_back({dfn[r1],dfn[r2],i});
    }
    for(auto [x,y]:d){
        add.push_back({dfn[x],dfn[y],1});
        add.push_back({dfn[x],dfn[y]+siz[y],-1});
        add.push_back({dfn[x]+siz[x],dfn[y],-1});
        add.push_back({dfn[x]+siz[x],dfn[y]+siz[y],1});
    }
    sort(add.begin(),add.end(),[](const node &x,const node &y){return x.x<y.x;});
    sort(qry.begin(),qry.end(),[](const node &x,const node &y){return x.x<y.x;});
    for(int i=0,j=0;i<qry.size();i++){
        for(;j<add.size()&&add[j].x<=qry[i].x;j++)
            bit::add(add[j].y,add[j].id);
        ans[qry[i].id]=bit::qry(qry[i].y);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    
}