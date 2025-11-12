#include <bits/stdc++.h>
#define int long long
using namespace std;
int T=  0;
int n = 0;
struct qwq{
    int x,y,z;
    int mx; int mn;
    int md;
}a[100010];
vector <int> xx;
vector <int> yy;
vector <int> zz;
bool cmp(int p1, int p2){
    return a[p1].md - a[p1].mx > a[p2].md - a[p2].mx;
}
void slv(){
    cin >> n; int as = 0; xx.clear(); yy.clear(); zz.clear();
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].mx = max(a[i].x, max(a[i].y, a[i].z));
        a[i].mn = min(a[i].x, min(a[i].y, a[i].z));
        a[i].md = a[i].x + a[i].y + a[i].z - a[i].mx - a[i].mn;
        if(a[i].x >= a[i].y && a[i].x >= a[i].z){
            xx.push_back(i); as += a[i].x;
        }
        else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
            yy.push_back(i); as += a[i].y;
        }
        else if(a[i].z >= a[i].y && a[i].z >= a[i].x){
            zz.push_back(i); as += a[i].z;
        }
    }
    if(xx.size() * 2 <= n && yy.size() * 2 <= n && zz.size() * 2 <= n){
        cout << as << '\n'; return;
    }
    if(xx.size() < yy.size()) swap(xx, yy);
    if(xx.size() < zz.size()) swap(xx, zz);
    // cout << xx.size() << " ---\n";
    sort(xx.begin(), xx.end(), cmp);
    // for(int v : xx){
    //     cout << v << " .";
    // } cout << '\n';
    for(int i = 0; i <= xx.size() - (n >> 1) - 1; i++){
        as += a[xx[i]].md - a[xx[i]].mx;
    } cout << as << '\n'; return;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T --){
        slv();
    } return 0;
}