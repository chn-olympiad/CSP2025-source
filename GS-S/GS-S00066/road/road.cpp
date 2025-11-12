#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
#ifdef DEBUG
#define dbg(x) cout<<__LINE__<<": " << (#x) << "="<<(x)<<"\n"
#else
#define dbg(x)
#endif // DEBUG

struct Road {
    int u,v,w;
    Road(int u=0, int v=0, int w=0): u(u),v(v),w(w) {}
};

struct Cun {
    int c;
    vector<int> a;
    Cun(int c=0, vector<int> a= {}): a(a),c(c) {}
};

struct City {
    vector<Road> roads;

};

bool checkA( vector<Road>& roads, vector<Cun> &cuns) {
    for(int i=1; i<cuns.size() ; i++) {
        if(cuns[i].c != 0) {
            return false;
        }
    }
    return true;
}

int solveA(int n, int m, int k, vector<Road>& roads, vector<Cun> &cuns ) {
    for(int i=1; i<=k; i++) {
        for(int j=1; j< cuns[i].a.size(); j++) {
            if(cuns[i].a[j] == 0) {
                for(int k=1; k<m; k++) {
                    if(k!=j) {
                        roads.push_back(Road(i,j,0));
                    }
                }
            }
        }
    }

    vector<bool> visitedCity(m);
    vector<bool> visitedRoad(n);
    vector<int> cityPrice(m, INT_MAX);
    queue<int> q;

    int curCity = roads[1].u;
    cityPrice[curCity] = 0;
    visitedCity[curCity] = true;

    while(!q.empty()) {
        curCity = q.front();
        q.pop();
        for(int i = 1; i<roads.size(); i++) {
            if(!visitedCity[roads[i].v] && roads[i].u == curCity) {
                q.push(i);
                dbg([roads[i].u);
                dbg([roads[i].v);
                dbg([roads[i].w);
                cityPrice[roads[i].v] = min(roads[i].w + cityPrice[roads[i].u],cityPrice[roads[i].v]);
                visitedCity[roads[i].v] = true;
            }
        }
    }

    int res = 0;
    for(int i=1; i<cityPrice.size(); i++) {
        res = max(res,cityPrice[i]);
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream cin("road.in");
    ofstream cout("road.out");

    int n,m,k;
    cin >> n>>m>>k;

    vector<Road> roads(m+1);
    vector<Cun> cuns(k+1,Cun(0,vector<int>(n+1)));
    for(int i=1; i<=m; i++) {
        cin >> roads[i].u >> roads[i].v >> roads[i].w;
    }
    for(int i=1; i<=n; i++) {
        cin >> cuns[i].c;
        for(int j=1; j<=n; j++) {
            cin >> cuns[i].a[j];
        }
    }
    int res=0;
    if(checkA(roads,cuns)) {
        res = solveA(n,m,k,roads,cuns);
    } else {
        res = solveA(n,m,k,roads,cuns);
    }

    cout << res << "\n";

    return 0;
}
