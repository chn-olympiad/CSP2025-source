#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long c[10015];
bool v[10015];
struct St{
    int u,v;
    long long w;
};
bool cmp(St a,St b){
    return a.w<b.w;
}
vector<St> st;
long long sum,ans=1e18;
int f[10015];
int Find(int x){
    if(x==f[x]) return x;
    return f[x]=Find(f[x]);
}
void solve(int x,long long y){
    int cnt=0;
    sum=y;
    for(int i=1;i<=n+k;i++) f[i]=i;
    for(int i=0;i<st.size();i++){
        if(cnt>=x) return;
        if(v[st[i].u]) continue;
        if(Find(st[i].u)!=Find(st[i].v)){
            f[Find(st[i].v)]=Find(st[i].u);
            sum+=st[i].w;
            cnt++;
        }
    }
    return;
}
void dfs(int x,int y,long long z){
    if(x>n+k){
        solve(y,z);
        ans=min(ans,sum);
        return;
    }
    v[x]=1;
    dfs(x+1,y,z);
    v[x]=0;
    dfs(x+1,y+1,z+c[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        st.push_back(St{u,v,w});
    }
    long long s=0;
    for(int i=n+1;i<=n+k;i++){
        scanf("%lld",&c[i]);
        s+=c[i];
        for(int j=1;j<=n;j++){
            long long a;
            scanf("%lld",&a);
            st.push_back(St{i,j,a});
        }
    }
    sort(st.begin(),st.end(),cmp);
    if(!s){
        solve(n+k,0);
        printf("%lld\n",sum);
        return 0;
    }
    dfs(n+1,n,0);
    printf("%lld\n",ans);
    return 0;
}
