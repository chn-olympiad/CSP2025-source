#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep1(a) for(int i = 1;i <= a;i++)
#define rst(a) for (auto to:(a))
#define all(a) (a).begin(),(a).end()
#define pb push_back
typedef pair<int,int> pi;
const int mod = 1e9 + 7,inf = 0x3f3f3f3f,N = 5e5 + 10;
int a[N],sum[N];
vector<pi> g;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,ans = 0;
    cin >> n >> k;
    rep1(n) cin >> a[i];
    rep1(n) sum[i] = sum[i - 1] ^ a[i];
    rep1(n) for(int j = 1;j <= i;j++) if ((sum[i] ^ sum[j-1]) == k) g.pb({i,j});
    sort(all(g));
    int now = 1;
    rst(g){
        if (to.se >= now) ans ++,now = to.fi + 1;
    }
    cout << ans << endl;
    return 0;
}
