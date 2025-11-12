#include <bits/stdc++.h>
using namespace std;
#define M 99824435399999
#define B 1331
string ta[200010],tb[200010],tc[200010],td[200010];
int tr[11000010][26],tot,dfn[11000010],sz[11000010],tot2;
int ka[200010],kb[200010],kc[200010],kd[200010],ans[200010];
vector <char> vc[11000010];
struct Trie{
    int root;
    int insert(string s){
        int id=root;
        for (auto x:s){
            if (!tr[id][x-'a']){
                tr[id][x-'a']=++tot;
                vc[id].push_back(x-'a');
            }
            id=tr[id][x-'a'];
        }
        return id;
    }
    void dfs(int id){
        dfn[id]=++tot2;
        sz[id]=1;
        for (auto x:vc[id]){
            dfs(tr[id][x]);
            sz[id]+=sz[tr[id][x]];
        }
    }
};
struct node{
    int l,r,x;
    bool operator <(const node&a)const{
        return l<a.l;

    }
};
map <pair<long long,long long>,vector <int>> mpa,mpb;
int C[15000010];
void inssert(int id,int num){
    while (id<=tot) C[id]+=num,id+=(id&-id);
}
int query(int id){
    int sum=0;
    while (id) sum+=C[id],id-=(id&-id);
    return sum;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for (int i=1; i<=n; i++){
        string a,b; cin>>a>>b;
        if (a==b) continue;
        int mx=0,mn=a.size()+1;
        for (int j=0; j<a.size(); j++){
            if (a[j]!=b[j]){
                mx=max(mx,j);
                mn=min(mn,j);
            }
        }
        for (int j=mn-1; j>=0; j--) ta[i]+=a[j];
        for (int j=mx+1; j<a.size(); j++) tb[i]+=a[j];
        long long tmpa=0,tmpb=0;
        for (int j=mn; j<=mx; j++){
            tmpa=(tmpa*B+a[j])%M;
            tmpb=(tmpb*B+b[j])%M;
        }
        mpa[make_pair(tmpa,tmpb)].push_back(i);
        //cout<<i<<" "<<a<<" "<<b<<"\n";;
    }
    for (int i=1; i<=m; i++){

        string a,b; cin>>a>>b;
        if (a==b||a.size()!=b.size()) continue;
        int mx=0,mn=a.size()+1;
        for (int j=0; j<a.size(); j++){
            if (a[j]!=b[j]){
                mx=max(mx,j);
                mn=min(mn,j);
            }
        }
        for (int j=mn-1; j>=0; j--) tc[i]+=a[j];
        for (int j=mx+1; j<a.size(); j++) td[i]+=a[j];
        long long tmpa=0,tmpb=0;
        for (int j=mn; j<=mx; j++){
            tmpa=(tmpa*B+a[j])%M;
            tmpb=(tmpb*B+b[j])%M;
        }
        mpb[make_pair(tmpa,tmpb)].push_back(i);//cout<<"aa"<<i<<a<<" "<<b<<endl;//cout<<"aa"<<i<<" "<<a<<" "<<b<<"\n";
    }//cout<<"WOW"<<endl;
    for (auto x:mpa){
        auto key=x.first;
        Trie t; t.root=++tot;
        for (auto i:mpa[key]) ka[i]=t.insert(ta[i]),kb[i]=t.insert(tb[i]);
        for (auto i:mpb[key]) kc[i]=t.insert(tc[i]),kd[i]=t.insert(td[i]);
        t.dfs(t.root);
        vector <pair<int,node>> vi;
        vector <pair<int,pair<int,int>>> vq;
        for (auto i:mpa[key]){
            vi.push_back(make_pair(dfn[ka[i]],node{dfn[kb[i]],dfn[kb[i]]+sz[kb[i]]-1,1}));
            vi.push_back(make_pair(dfn[ka[i]]+sz[ka[i]],node{dfn[kb[i]],dfn[kb[i]]+sz[kb[i]]-1,-1}));
        }
        for (auto i:mpb[key]){
            vq.push_back(make_pair(dfn[kc[i]],make_pair(dfn[kd[i]],i)));
        }
        //cout<<key.first<<endl;
        sort(vi.begin(),vi.end());
        sort(vq.begin(),vq.end());
        int id=0;
        for (auto x:vq){
            while (id<vi.size()&&vi[id].first<=x.first){
                inssert(vi[id].second.l,vi[id].second.x);
                inssert(vi[id].second.r+1,-vi[id].second.x);
                id++;
            }
            ans[x.second.second]+=query(x.second.first);
        }
        while (id<vi.size()){
            inssert(vi[id].second.l,vi[id].second.x);
            inssert(vi[id].second.r+1,-vi[id].second.x);
            id++;
        }
    }
    for (int i=1; i<=m; i++) cout<<ans[i]<<"\n";
}
