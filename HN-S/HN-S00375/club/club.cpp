#include<bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) v.begin(),v.end()
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=1e5+5,inf=1e18;
int n;
struct node{
    int a[3],val;
}p[N];
vector<int> v[3];
inline int read(){
    register int x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)){t|=(ch=='-');ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return t?-x:x;
}
inline void work(){
    n=read();
    int lim=n/2;
    fill(v,v+3,vector<int>());
    int res=0;
    for(int i=1;i<=n;i++){
        int max_num=0;
        for(int j=0;j<3;j++){
            p[i].a[j]=read();
            if(p[i].a[max_num]<p[i].a[j]) max_num=j;
        }
        p[i].val=inf;
        for(int j=0;j<3;j++){
            if(j^max_num) p[i].val=min(p[i].val,p[i].a[max_num]-p[i].a[j]);
        }
        v[max_num].emplace_back(i);
        res+=p[i].a[max_num];
    }
    if(max({v[0].size(),v[1].size(),v[2].size()})<=lim){
        printf("%lld\n",res);
        return;
    }
    int maxn=0;
    for(int i=0;i<3;i++) if(v[i].size()>lim) maxn=i;
    sort(v[maxn].begin(),v[maxn].end(),[&](int x,int y){return p[x].val<p[y].val;});
    for(int i=1;i<=v[maxn].size()-lim;i++) res-=p[v[maxn][i-1]].val;
    printf("%lld\n",res);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--) work();
    return 0;
}