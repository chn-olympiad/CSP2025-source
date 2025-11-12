#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+9, V = 26, M = 5e6+9, L = N*21;

int n, q;
string s1[N], s2[N];
string t1[N], t2[N];
string s[N], t[N];

int ncnt;
int son[M][V];
vector<int> tt[M];
int fal[M];

void insert(string &ts, int id){
    int p = 0;
    for(int i = 0; i < ts.size(); i++){
        int j = ts[i]-'a';
        if(!son[p][j]) son[p][j] = ++ncnt;
        p = son[p][j];
    }
    tt[p].push_back((int)ts.size());
}

int nc;
const int vm = 5e6;
int rt[M];
struct node{
    int dat, ls, rs;
}st[L];

int add(int pre, int l, int r, int x, int k){
    int p = ++nc;
    st[p] = st[pre];
    if(l == r){
        st[p].dat += k;
        return p;
    }
    int mid = (l+r)/2;
    if(x <= mid) st[p].ls = add(st[p].ls, l, mid, x, k);
    else st[p].rs = add(st[p].rs, mid+1, r, x, k);
    st[p].dat += k;
    return p;
}

int query(int p, int l, int r, int s, int t){
    if(!p) return 0;
    if(s <= l && r <= t) return st[p].dat;
    int mid = (l+r)/2;
    if(t <= mid) return query(st[p].ls, l, mid, s, t);
    if(s > mid) return query(st[p].rs, mid+1, r, s, t);
    return query(st[p].ls, l, mid, s, t)+query(st[p].rs, mid+1, r, s, t);
}

int he[M], ne[M], to[M], ecnt;

void add(int x, int y){
    ne[++ecnt] = he[x];
    he[x] = ecnt;
    to[ecnt] = y;
}

void dfs(int x){
    for(int i : tt[x]){
        rt[x] = add(rt[x], 1, vm, i, 1);
    }
    for(int i = he[x]; i; i = ne[i]){
        int y = to[i];
        rt[y] = rt[x];
        dfs(y);
    }
}

void build(){
    queue<int> que;
    for(int i = 0; i < V; i++){
        if(son[0][i]) que.push(son[0][i]);
    }
    while(!que.empty()){
        int x = que.front();
        que.pop();
        for(int i = 0; i < V; i++){
            if(!son[x][i]){
                son[x][i] = son[fal[x]][i];
            }else{
                fal[son[x][i]] = son[fal[x]][i];
                que.push(son[x][i]);
            }
        }
    }
    for(int i = 1; i <= ncnt; i++){
        add(fal[i], i);
    }
    dfs(0);
}

int main(){

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>s1[i]>>s2[i];
        for(int j = 0; j < s1[i].size(); j++){
            s[i] += s1[i][j];
            s[i] += s2[i][j];
        }
        insert(s[i], i);
    }

    build();

    for(int i = 1; i <= q; i++){
        cin>>t1[i]>>t2[i];
        for(int j = 0; j < t1[i].size(); j++){
            t[i] += t1[i][j];
            t[i] += t2[i][j];
        }
        if(t1[i].size() != t2[i].size()){
            cout<<0<<endl;
            continue;
        }
        int l = 0, r = t1[i].size()-1;
        while(t1[i][l] == t2[i][l]){
            l++;
        }
        while(t1[i][r] == t2[i][r]){
            r--;
        }
        long long ans = 0;
        int p = 0;
        for(int k = 0; k < t[i].size(); k++){
            int j = t[i][k]-'a';
            p = son[p][j];
            if((k&1) && k >= r*2+1){
                ans += query(rt[p], 1, vm, k+1-l*2, vm);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}