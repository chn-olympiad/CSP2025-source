#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll MOD = 998244353;
int n,m;
string s;
vector<pair<int,int> > c;
int ans = 0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    c.resize(n+1);
    for(int i = 1;i<=n;i++){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.begin()+1,c.end());
    do{
        int cnt = 0,lc = 0;
        for(int i = 1;i<=n;i++){
            if(s[i]=='0'){
                lc++;
                continue;
            }
            if(lc>=c[i].first){
                lc++;
                continue;
            }
            cnt++;
            if(cnt>=m){
                ans = (ans + 1)%MOD;
                break;
            }
        }
    }while(next_permutation(c.begin()+1,c.end()));
    cout << ans << '\n';
    return 0;
}
/*
g++ A.cpp -o A
./A

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

4
10 9 8
4 0 0
5 4 3
0 0 20
*/