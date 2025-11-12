#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i = (a); i <= (b); i+=(c))
#define per(i,a,b,c) for(int i = (a); i >= (b); i-=(c))
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second
using namespace std;
using PII = pair<int,int>;
using PPII = pair<int,pair<int ,int>>;
const int INF = INT_MAX / 2;
const int N = 1e5 + 5;

int n, m, k;
vector<PII> g[N];
int up[N];
int cost[10][N];

bool isFull0 = true;

priority_queue<PPII,vector<PPII>,greater<PPII>> q;


int p[N];

int fr(int s){
    if(p[s] != s) return fr(p[s]);
    return p[s];
}

void join(int x, int y){
    x = fr(x), y = fr(y);
    if(x != y)
        p[y] = x;
}

int tot = 0;

void f(){
    while(q.size()){
        int u = q.top().y.x, v = q.top().y.y, w = q.top().x;
        q.pop();
        if(fr(u) == fr(v)) continue;
        tot += w;
        join(u,v);
//        printf("%d <--> %d\n",u,v);
    }
}


int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	rep(i,1,n,1) p[i] = i;
	rep(i,1,m,1){
        int u, v, w;
        cin >> u >>v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        q.push({w,{u,v}});
	}

	rep(i,1,k,1){
        cin >> up[i];
        rep(i,1,n,1){
            cin >> cost[i][j];
            if(cost[i][j] != 0){
                isFull0 = false;
            }
        }
	}

	if(k == 0){
        f();
        cout << tot << endl;
        return 0;
	}
	return 0;
}
