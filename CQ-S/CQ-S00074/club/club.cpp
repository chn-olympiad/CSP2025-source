#include<iostream>
#include<set>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N][3],d[N],ct[3];
struct node{
    int x,v;
    friend bool operator < (const node &a,const node &b){
        return a.v>b.v||(a.v==b.v&&a.x<b.x);
    }
};
set<node> s[3][3];
void add(int x,int p1,int p2){
    s[p1][p2].insert({x,a[x][p2]-a[x][p1]});
}
struct ask{int v,p,to;};
ask get(){
    ask ans={-1000000000,0,0};
    for(int i:{0,1,2}) for(int j:{0,1,2}){
        if(i==j||s[i][j].empty()) continue;
        int v=s[i][j].begin()->v;
        if(ct[j]==n/2) v+=s[j][i].begin()->v;
        if(ans.v<v) ans={v,i,j};
    }
    return ans;
}
void del(int o,int d){
    for(int j:{0,1,2}) if(j!=d){
        s[d][j].erase({o,a[o][j]-a[o][d]});
    }
    ct[d]--;
}
void insert(int o,int d){
    ::d[o]=d,ct[d]++;
    for(int j:{0,1,2}) if(j!=d){
        s[d][j].insert({o,a[o][j]-a[o][d]});
    }
}
void solve(){
    cin>>n;
    ct[0]=ct[1]=ct[2]=0;
    for(int i:{0,1,2}) for(int j:{0,1,2}) s[i][j].clear();
    for(int i=1;i<=n;i++) for(int j:{0,1,2}){
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        d[i]=i%3;
        for(int j:{0,1,2}) if(j!=d[i]){
            add(i,d[i],j);
        }
        ct[d[i]]++;
    }
    auto f=get();
    while(f.v>0){
        int o=s[f.p][f.to].begin()->x,p=-1;
        if(ct[f.to]>=n/2) p=s[f.to][f.p].begin()->x;
        del(o,f.p),insert(o,f.to);
        if(p!=-1) del(p,f.to),insert(p,f.p);
        f=get();
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i][d[i]];
    cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int T;cin>>T;
    while(T--) solve();
	return 0;
}