#include<bits/stdc++.h>
#define ull unsigned long long
#define B 458791
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
int len1[200005],len2[200005],ans[200005];
struct NODE{
    int op,pre,suf,id;
    ull ha;
};
bool operator < (NODE x,NODE y){
    return x.ha<y.ha;
}
struct tire{
    int ch[26];
}a[2][5000005];
int cnt[2];
void clear(int id=2){
    if(id==2){clear(0),clear(1);return ;}
    for(int i=1;i<=cnt[id];i++){
        for(int j=0;j<26;j++) a[id][i].ch[j]=0;
    }
    cnt[id]=1;
}
int insert(string s,int id){
    int now=1;
    for(int i=0;i<s.size();i++){
        if(!a[id][now].ch[s[i]-'a']) a[id][now].ch[s[i]-'a']=++cnt[id];
        now=a[id][now].ch[s[i]-'a'];
    }
    return now;
}
int p1[400005],p2[400005];
int L[5000005][2],R[5000005][2],dfn;
void dfs(int now,int id){
    L[now][id]=++dfn;
    for(int i=0;i<26;i++){
        if(a[id][now].ch[i]==0) continue;
        dfs(a[id][now].ch[i],id);
    }
    R[now][id]=dfn;
}
struct node{
    int op,l,r,x,y,id,val;
};vector<node> vec;
struct b1t{
    int c[5000005];
    #define lb(x) (x&-x)
    void add(int x,int k){
        while(x<=cnt[1]){
            c[x]+=k;
            x+=lb(x);
        }
    }
    int ask(int x){
        int ret=0;
        while(x){
            ret+=c[x];
            x-=lb(x);
        }return ret;
    }
    void add(int l,int r,int k){
        add(l,k);add(r+1,-k);
    }
}T;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    vector<NODE> V;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        len1[i]=s1[i].size();
        s1[i]='#'+s1[i];
        s2[i]='#'+s2[i];
        int pre=0;
        while(pre<len1[i]&&s1[i][pre+1]==s2[i][pre+1]) pre++;
        if(pre==len1[i]) continue;
        int suf=len1[i]+1;
        while(suf>1&&s1[i][suf-1]==s2[i][suf-1]) suf--;
        ull ha=0;
        for(int j=pre+1;j<suf;j++) ha=ha*B+s1[i][j];
        for(int j=pre+1;j<suf;j++) ha=ha*B+s2[i][j];
        V.push_back({0,pre,suf,i,ha});
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        if(t1[i].size()!=t2[i].size()) continue;
        len2[i]=t1[i].size();
        t1[i]='#'+t1[i];
        t2[i]='#'+t2[i];
        int pre=0;
        while(pre<len2[i]&&t1[i][pre+1]==t2[i][pre+1]) pre++;
        if(pre==len2[i]) continue;
        int suf=len2[i]+1;
        while(suf>1&&t1[i][suf-1]==t2[i][suf-1]) suf--;
        ull ha=0;
        for(int j=pre+1;j<suf;j++) ha=ha*B+t1[i][j];
        for(int j=pre+1;j<suf;j++) ha=ha*B+t2[i][j];
        V.push_back({1,pre,suf,i,ha});
    }
    sort(V.begin(),V.end());
    for(int l=0;l<V.size();l++){
        int r=l;
        while(r+1<V.size()&&V[r+1].ha==V[l].ha) r++;
        clear();
        for(int i=l;i<=r;i++){
            string Pre;
            for(int j=V[i].pre;j;j--){
                if(V[i].op==0){
                    Pre+=s1[V[i].id][j];
                }else Pre+=t1[V[i].id][j];
            }
            p1[i]=insert(Pre,0);
            string Suf;
            int lim;
            if(V[i].op==0) lim=len1[V[i].id];
            else lim=len2[V[i].id];
            for(int j=V[i].suf;j<=lim;j++){
                if(V[i].op==0){
                    Suf+=s1[V[i].id][j];
                }else Suf+=t1[V[i].id][j];
            }
            p2[i]=insert(Suf,1);
        }

        dfn=0;dfs(1,0);
        dfn=0;dfs(1,1);
        // // node -> op,l,r,x,y,id,val;
        vec.clear();
        for(int i=l;i<=r;i++){
            int now1=p1[i],now2=p2[i];
            if(V[i].op==0){
                // cout<<L[now1][0]<<" "<<R[now1][0]<<' '<<L[now2][1]<<' '<<R[now2][1]<<'\n';
                vec.push_back((node){0,L[now2][1],R[now2][1],L[now1][0],-1,-1,1});
                vec.push_back((node){0,L[now2][1],R[now2][1],R[now1][0]+1,-1,-1,-1});
            }
            else{
                // cout<<L[now1][0]<<' '<<L[now2][1]<<'\n';
                vec.push_back((node){1,-1,-1,L[now1][0],L[now2][1],V[i].id,-1});
            }
        }
        sort(vec.begin(),vec.end(),[](node x,node y){
            if(x.x==y.x){
                return x.op<y.op;
            }return x.x<y.x;
        });
        for(auto u:vec){
            if(u.op==0){
                T.add(u.l,u.r,u.val);
            }
            else{
                // cout<<u.id<<' '<<u.x<<' '<<u.y<<'\n';
                ans[u.id]=T.ask(u.y);
            }
        }
        for(auto u:vec){
            if(u.op==0){
                T.add(u.l,u.r,-u.val);
            }
        }
        // cout<<'\n';
        
        l=r;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
/*
最后一次 CSPS，AK 了？人生第一次啊
CCF 别卡我常求你了

为什么在高二却输了呢。
lfxxx 24+10+5
*/