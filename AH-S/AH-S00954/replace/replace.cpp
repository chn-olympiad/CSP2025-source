#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=200050;
long long akcsp(string s){
    long long x=0;
    for(int i=0;i<s.size();i++){
        x*=101;
        x+=s[i];
        x%=11451419198101ll;
    }
    return x;
}
struct block{
    long long mid;
    string l,r;
    int tp;
};
bool cmp(block a,block b){
    return a.mid<b.mid;
}
block build(string s,string t){
    for(int j=0;j<s.size();j++){
        if(s[j]!=t[j]){
            for(int k=s.size()-1;k>=0;k--){
                if(s[k]!=t[k]){
                    string l=s.substr(0,j);
                    reverse(l.begin(),l.end());
                    string r=s.substr(k+1,s.size()-k-1);
                    string mid=s.substr(j,k-j+1)+t.substr(j,k-j+1);
                    //cout<<s<<" "<<t<<" "<<l<<" "<<mid<<" "<<r<<endl;
                    return {akcsp(mid),l,r,0};
                }
            }
        }
    }
}
int ans[MAXN];
void Insert(string s){
    int u=1;
    int otot=tot;
    for(int i=0;i<s.size();i++){
        int &t=a[u][s[i]-'a'];
        if(!t)t=++tot,fa[t]=u,c[t]=s[i];
        u=t;
    }
    int tmp=0;
    while(u){if(u>otot)tmp++;sz2[u]+=tmp,u=fa[u],sz[u]++;}
}
int Find(string s){
    int u=1;
    for(int i=0;i<s.size();i++){
        u=a[u][s[i]-'a'];
    }
    return u;
}
void Del(string s){
    int u=Find(s);
    while(u!=0){
        sz[u]--;
        if(sz[u]==0){
            a[fa[u]][c[u]]=0;
        }
        u=fa[u];
    }
}
void Build(vector<string>v){
    sz2[1]=1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        Insert(v[i]);
    }
}
struct Block{
    int x,y,tp;
};
bool winner(Block a,Block b){
    if(a.x!=b.x)return a.x<b.x;
    return a.tp<b.tp;
}
const int MAXS=10000000;
struct BIT{
    int c[10000050];
    void add(int x,int v){
        while(x<=MAXS)c[x]+=v,x+=x&-x;
    }
    int sum(int x){
        int s=0;while(x)s+=c[x],x-=x&-x;return s;
    }
};
void solve(vector<block>&v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i].tp>0&&v[j].tp<0){
                ans[v[i].tp]+=(v[i].l.find(v[j].l)==0&&v[i].r.find(v[j].r)==0);
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<block>v;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s>>t;
        if(s==t)continue;
        v.push_back(build(s,t));
        v.back().tp=-i;
    }
    for(int i=1;i<=m;i++){
        string s,t;
        cin>>s>>t;
        v.push_back(build(s,t));
        v.back().tp=i;
    }
    sort(v.begin(),v.end(),cmp);
    vector<block>u;
    //cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        if(i&&v[i].mid!=v[i-1].mid)solve(u),u.clear();
        u.push_back(v[i]);
    }
    solve(u);
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
