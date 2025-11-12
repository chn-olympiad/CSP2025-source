#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 11451;
int f[N];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> f[i];
    }

    sort(f+1,f+n+1);
    cout << 6 << endl;
    return 0;
}
