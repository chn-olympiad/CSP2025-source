# include<bits/stdc++.h>
# define int long long
# define endl "\n"
using namespace std;
const int maxn=505, mod=998244353;
int n, m, s[maxn], c[maxn], a[maxn], ans=0;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        char c; cin >> c;
        s[i]=c-'0';
    }
    for(int i=1; i<=n; i++) cin >> c[i], a[i]=i;
    do {
        int now=0;
        for(int i=1; i<=n; i++) {
            if(now>=c[a[i]]) now++;
            else if(s[i]==0) now++;
        }
        if(now<=n-m) ans++, ans%=mod;
    } while(next_permutation(a+1, a+n+1));
    cout << ans << endl;
    fclose(stdin); fclose(stdout);
	return 0;
}
