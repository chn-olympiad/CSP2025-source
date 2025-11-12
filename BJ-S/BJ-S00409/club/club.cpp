#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
vector<ll> A;
vector<ll> B;
vector<ll> C;
void solve(){

    A.clear();
    B.clear();
    C.clear();

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i] >> c[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i] >= b[i] && a[i] >= c[i]){
            ans += a[i];
            A.push_back(a[i] - max(b[i], c[i]));
        }else if(b[i] >= a[i] && b[i] >= c[i]){
            ans += b[i];
            B.push_back(b[i] - max(a[i], c[i]));
        }else{
            ans += c[i];
            C.push_back(c[i] - max(a[i], b[i]));
        }
    }

    if(A.size() > n / 2){

        int len = A.size() - n / 2;
        sort(A.begin(), A.end());
        for(int i = 0; i < len; i ++){
            ans -= A[i];
        }

    }else if(B.size() > n / 2){

        int len = B.size() - n / 2;
        sort(B.begin(), B.end());
        for(int i = 0; i < len; i ++){
            ans -= B[i];
        }
    }else {
        int len = C.size() - n / 2;
        sort(C.begin(), C.end());
        for(int i = 0; i < len; i ++){
            ans -= C[i];
        }
    }
    cout << ans << endl;
}

int main(){

    ios::sync_with_stdio();
    cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while(t --) solve();

    return 0;
}
