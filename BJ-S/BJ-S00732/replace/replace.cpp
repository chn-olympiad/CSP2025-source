#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q;
string a[10050][2];
ll lg[10050];

void sol(){
	string x, y;
	for (ll i = 0; i < n; i ++){
		cin >> a[i][0] >> a[i][1];
		for (char j : a[i][0]) lg[i]++;
	}
	for(int bb = 0; bb < q; bb++){
		cin >> x >> y;
		vector<ll> c;
		ll cnt = 0;
		for (char i : x) cnt++;
		for (ll i = 0; i < cnt; i ++){
			if(x[i]!=y[i]){
				c.push_back(i);
			}
		}
		cnt = 0;
		for (ll i = 0; i < n; i++){
			for(ll j = 0; j < lg[i]; j++){
				if(a[i][0][j] == x[c[0]] && a[i][1][j] == y[c[0]]){
					cnt++;
					break;
				}
			}
		}
		if(cnt == 0) cnt = 1;
		cout << cnt-1 << "\n";
	}
	return;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
	sol();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
