#include<bits/stdc++.h>
using namespace std;
const int M = 1000006;
int n,m,k,x,y,z,cnt,siz[M];
long long build,ans,ans2;
int fa[M];
struct node{
    long long cst;
    int from,targ;
    bool operator > (const node&l)const{
        return cst > l.cst;
    }
};
int find(int p){
    if(fa[p]==p)return p;
    return fa[p]=find(fa[p]);
}
void merge(int o,int p){
    if(siz[o] > siz[p]){
        fa[p]=fa[o];
    }
    if(siz[o]==siz[p]){
        siz[p]++;
        fa[o]=fa[p];
    }
    else fa[o]=fa[p];
}
vector <node> v[M*5];
int value[15][M];
priority_queue <node,vector <node> ,greater<node> > q;
priority_queue <node,vector <node> ,greater<node> > q2;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    for(int i = 1; i <= n; i++){
        fa[i]=i;
    }
    for(int i = 1; i <= m; i++){
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&z);
        q.push({z,x,y});
        q2.push({z,x,y});
    }
    while(!q.empty()){
        node tp = q.top();
        q.pop();
        int cost = tp.cst;
        int a = find(tp.from);
        int b = find(tp.targ);
        if(a == b)continue;
        merge(a,b);
        ans += cost;
    }
    for(int i = 1; i <= n+k; i++){
        fa[i]=i;
    }
    for(int i = 1; i <= k; i++){
        cin >>build;
        q2.push({build,-1,i});
        for(int j = 1; j <= n; j++){
            cin >> value[i][j];
        }
    }
    if(k == 0){
        cout <<ans;
        return 0;
    }
    while(!q2.empty()){
        node tp = q2.top();
        q2.pop();
        int cost = tp.cst;
        int a = find(tp.from);
        int b = find(tp.targ);
        int cntt = 0;
        for(int i = 1; i <= n; i++){
            if(find(i) == find(1)){
                cntt++;
            }
        }
        if(cntt == n)break;
        if(tp.from == -1){
            ans2+=cost;
            for(int j = 1; j <= n; j++){
                q2.push({value[b][j],n+b,j});
            }
            continue;
        }
        if(a == b)continue;
        merge(a,b);
        ans2 += cost;
    }
    cout << min(ans,ans2);
    return 0;
}
