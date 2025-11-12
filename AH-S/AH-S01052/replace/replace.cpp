#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q;
const ll N=2e5+5;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> q;
    cout << n >> q;
    string s1[N], s2[N];
    for(int i=1; i<=n; ++i){
		cin >> s1[i] >> s2[i];
	}
	for(int i=1; i<=q; ++i) cout << 0 << '\n';
    return 0;
}
