#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4e6 + 10;
int nm;
struct node{
    int x,y,val;
};
int tmp[maxn ],tex[maxn ];
vector<node>v(maxn );
vector<int>pl;
const int MAX = 1e17;
int f[maxn ];
int n,m,k;
int a[maxn];
int Find(int x){
    if(f[x] == x) return x;
    return f[x] = Find(f[x]);
}
void Link(int x,int y){
    f[Find(x)] = Find(y);
}
bool cmp(node x,node y){
    return x.val < y.val;
}
void work1(){
    for(int i = 1 ; i <= n ; i ++) f[i] = i;
    int answ = 0;
    sort(&v[1],&v[1 + 2 * m],cmp);
    for(int i = 1 ; i <= 2 * m ; i ++){
        int x = v[i].x , y = v[i].y ,val = v[i].val;
        if(Find(x) != Find(y)){
            Link(x,y);
            answ += val;
        }
    }
    cout << answ;

}

int work2(int tp){
    for(int i = 1 ; i <= n ; i ++) tmp[i] = 0;
    for(int i = 1 ; i <= nm ; i ++) tex[i] = 0;
    for(int i = 1 ; i <= nm ; i ++) f[i] = i;
    pl.clear();
    int tot = 0,answ = 0;
    
    for(int i = 1 ; i <= nm ; i ++){
        int x = v[i].x , y = v[i].y ,val = v[i].val;
        if(Find(x) != Find(y)){
            if(x > n) {
                if(!tex[x]) pl.push_back(x);
                tex[x] ++;
            }
            if(y > n) {
                if(!tex[y]) pl.push_back(y);
                tex[y] ++;
            }
            tmp[x] = tmp[y] = 1;
            Link(x,y);
            answ += val;
            ++ tot;
        }
        if(tot == tp) break;
    }
    for(int i = 1 ; i <= n ; i ++) {
        if(!tmp[i]) return MAX;
    }
    //cout << "answ:" << answ << " sz:" << q.size(); 
    for(auto itr:pl){
        answ -= (tex[itr] - 1) * a[itr];
    }
   // cout << " tex:" << tex[n + 1] << " a:" << a[n + 1] << endl;
    return answ;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cout << 1122;
    cin >> n >> m >> k;

    for(int i = 1 ; i <= m ; i ++){
        int x,y,z;
        cin >> x >> y >> z;
        v[++ nm] = {x,y,z};
        v[++ nm] = {y,x,z};
    }
    for(int i = 1 ; i <= k ; i ++){
        cin >> a[i + n];
        for(int j = 1 ; j <= n ; j ++){
            int g;
            cin >> g;
            v[++ nm] = {i + n,j,g + a[i + n]};
            v[++ nm] = {j,i + n,g + a[i + n]};
        }
    }
    if(k == 0) work1();
    else {
        //cout << 10;
        int ans = MAX;
        //cout << ans;
        sort(&v[1],&v[1 + nm],cmp);
        for(int i = 0  ; i <= k ; i ++) {
            ans = min(ans,work2(i + n - 1));
            //cout << i << ' ' << ans << endl;
        }
        cout << ans;
    }
    
    return 0;
}
/*
4 5 0
1 2 2
2 4 1
2 3 2
3 4 8
1 4 3

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/