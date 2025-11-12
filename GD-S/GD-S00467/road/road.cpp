#include<bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i = l;i <= r;i ++)
#define dep(i,l,r) for(int i = l;i >= r;i --)
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;

int read(){
    int s = 0,w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

void chkmin(int &x,int y){x = min(x,y);}

struct node{
    int x;
    int y;
    int w;
}e[2000010],e2[200010];

int n,m,k;
pair <int,int> a[12][20010];
int pre[100010];
bool bk[20];
int ans = 1e18;
int tot;
int newm;
int id[20];
int pos[20];

void init(){rep(i,1,n + k)pre[i] = i;}

int find(int x){
    if(pre[x] == x)return x;
    return pre[x] = find(pre[x]);
}

void merge(int x,int y){
    int xx = find(x),yy = find(y);
    if(xx != yy)pre[xx] = yy;
}

bool cmp(node x,node y){return x.w < y.w;}

int kruskal(){
    newm = 0;
    init();
    int s = 0;
    int cnt = 0;
    rep(i,1,m){
        int x = e[i].x,y = e[i].y,w = e[i].w;
        if(find(x) != find(y)){
            e[++ newm] = {x,y,w};
            merge(x,y);
            s += w;
            cnt ++;
            if(cnt == n - 1){
                m = newm;
                return s;
            }
        }
    }
    return 1000000000000000000;
}

void doit(){
    tot = 0;
    int idx = 0;
    rep(i,1,k){
        if(!bk[i])continue;
        id[++ idx] = i;
        pos[i] = 1;
    }
    int all = 0;
    while(1){
        if(all >= n * idx)break;
        int mn = -1;
        rep(i,1,idx){
            if(pos[id[i]] == n + 1)continue;
            if(mn == -1 || a[id[i]][pos[id[i]]].first < a[mn][pos[mn]].first)mn = id[i];
        }
        e2[++ tot] = {mn + n,a[mn][pos[mn]].second,a[mn][pos[mn]].first};
        assert(mn != -1);
        pos[mn] ++;
        all ++;
       // cout<<"all = "<<all<<endl;
    }
}

int getans(int fll,int num){
    init();
    int s = fll;
    int cnt = 0;
    int l,r;l = 1,r = 1;
    while(1){
        if(s > ans)return 1000000000000000000;
        int x,y,w;
        if((e[l].w < e2[r].w && l <= m) || r > tot){
            x = e[l].x,y = e[l].y,w = e[l].w;
            l ++;
        }
        else {
            x = e2[r].x,y = e2[r].y,w = e2[r].w;
            r ++;
        }
       // cout<<"x = "<<x<<",y = "<<y<<endl;
        if(find(x) != find(y)){
            merge(x,y);
            
            s += w;
            cnt ++;
         //   cout<<"cnt = "<<cnt<<endl;
            if(cnt == n - 1 + num)return s;
        }
    }
    return 1000000000000000000;
}

void dfs(int dep,int now,int num){
    if(dep > k){
        doit();
        chkmin(ans,getans(now,num));
        return ;
    }
    rep(i,0,1){
        bk[dep] = i;
        dfs(dep + 1,now + a[dep][0].first * i,num + i);
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   // int s1 = clock();
    cin>>n>>m>>k;
    rep(i,1,m){
        int x,y,w;
        x = read(),y = read(),w = read();
        e[i] = {x,y,w};
    }
    rep(i,1,k){
        a[i][0].first = read();
        rep(j,1,n){
            a[i][j].first = read();
            a[i][j].second = j;
        }
        sort(a[i] + 1,a[i] + n + 1);
    }
    sort(e + 1,e + m + 1,cmp);
    chkmin(ans,kruskal());
    dfs(1,0,0);
    cout<<ans;
   // cout<<endl<<"time : "<<clock() - s1;
}
