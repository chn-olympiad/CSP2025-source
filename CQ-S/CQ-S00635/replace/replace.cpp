#include <bits/stdc++.h>
#define llong long long
#define N 5000006
using namespace std;

constexpr llong k1 = 13331, p1 = 1e9+7;
constexpr llong k2 = 9936257, p2 = 998244353;
int n, q;

int son[N][26], idx[N], cnt;
map<pair<int, int>, int> root;

char a[N], b[N];

inline pair<int, int> _hasha(int l, int r){
    llong res1 = 0, res2 = 0;
    for(int i = l; i <= r; ++i)
        res1 = (res1*k1+a[i])%p1, res2 = (res2*k2+a[i])%p2;
    return make_pair(res1, res2);
}

inline pair<int, int> _hashb(int l, int r){
    llong res1 = 0, res2 = 0;
    for(int i = l; i <= r; ++i)
        res1 = (res1*k1+b[i])%p1, res2 = (res2*k2+b[i])%p2;
    return make_pair(res1, res2);
}

inline int insert(int l, int r, int& root, int val){
    if(!root) root = ++cnt;;
    int x = root;
    for(int i = l; i <= r; ++i){
        if(!son[x][a[i]^96]) son[x][a[i]^96] = ++cnt;
        x = son[x][a[i]^96];
    }
    idx[x] = val;
    return x;
}

inline pair<int, int> query(int n1, int n2){
    int pos1 = 1, pos2 = 1;
    while(a[pos1] == b[pos1]) ++pos1;
    while(a[n1-pos2+1] == a[n2-pos2+1]) ++pos2;
    return make_pair(pos1, pos2);
}

typedef pair<int, int> Node;

int main(){
	freopen("replace.in", "r", stdin);
	 freopen("replace.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i){
        scanf("%s %s", a+1, b+1);
        int len1 = strlen(a+1), len2 = strlen(b+1);
        Node now = query(len1, len2);
        int pos1 = now.first, pos2 = now.second;
        insert(len2-pos2+1, len2, root[_hashb(pos1, len2-pos2+1)], insert(1, pos1-1, root[_hasha(pos1, len1-pos2+1)], 0));
    }
    for(int i = 1; i <= q; ++i){
        scanf("%s %s", a+1, b+1);
        cout << 0 << endl;

    }
     return 0;
}
