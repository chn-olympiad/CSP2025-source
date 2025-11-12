#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n;

ll ma(vector<ll> a){
    ll p = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > a[p])
            p = i;
    }
    return p;
}

void sol(){
    vector<vector<ll>> a;
    vector<vector<ll>> b;
    ll ans = 0;
    cin >> n;
    ll p = n/2;
    bool f = 1;
    for (ll i = 0; i < n; i++){
        ll t1=0, t2=0, t3=0;
        cin >> t1 >> t2 >> t3;
        a.push_back({t1, t2, t3});
        if(t2||t3) f = 0;
        if(t1>t2){
            if(t1>t3){
                b.push_back({t1, 1});
            }
            else{
                b.push_back({t3, 3});
            }
        }
        else{
            if(t2>t3){
                b.push_back({t2, 2});
            }
            else{
                b.push_back({t3, 3});
            }
        }

    }
    if(f){
        vector<ll> s;
        for (ll i = 0; i < n; i++){
            s.push_back(a[i][0]);
        }
        for (ll i = 0; i < p; i++){
            ll mx = ma(s);
            ans += s[mx];
            s[mx] = -2;
        }
        cout << ans << "\n";
        return;
    }
    ll c1=0, c2=0, c3=0;
    for (ll i = 0; i < n; i++){
        if(b[i][1] == 1)
            c1++;
        else if(b[i][1] == 2)
            c2++;
        else if(b[i][1] == 3)
            c3++;
    }
    if(c1 <= p&&c2<=p&&c3<=p){
        for (ll i = 0; i < n; i++){
            ans += b[i][0];
        }
        cout << ans << "\n";
        return;
    }
    if(n == 2){
		ll ma = 0, mb = 0;
		a[0][b[0][1]-1] = -1;
		a[1][b[0][1]-1] = -1;
		ma = max(a[0][0],max(a[0][1],a[0][2]));
		mb = max(a[1][0],max(a[1][1],a[1][2]));
		ans = max(ma+b[1][0],mb+b[0][0]);
		cout << ans << "\n";
	}
    return;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (ll i = 0; i < t; i++){
        sol();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
