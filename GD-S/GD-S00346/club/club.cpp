#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
const ll inf = 0x3f3f3f3f;
ll T, n;
ll a[N][4];
priority_queue <pair <ll, ll>, vector <pair <ll, ll> >, greater <pair <ll, ll> > > q1, q2, q3; // (val, id)
void ins1 (ll x, ll id) {
	if (q1.size () < n / 2) q1.push (make_pair (x, id));
	else {
		pair <ll, ll> p = q1.top ();
		q1.pop ();
		ll idx = p.second;
		if (a[idx][2] > a[idx][3] && q2.size () < n / 2) {
			q2.push (make_pair (a[idx][2], idx));
		} else if (q3.size () < n / 2) {
			q3.push (make_pair (a[idx][3], idx));
		} else return;		
		q1.push (make_pair (x, id));
	}
}
void ins2 (ll x, ll id) {
	if (q2.size () < n / 2) q2.push (make_pair (x, id));
	else {
		pair <ll, ll> p = q2.top ();
		q2.pop ();
		ll idx = p.second;
		if (a[idx][1] > a[idx][3] && q1.size () < n / 2) {
			q1.push (make_pair (a[idx][1], idx));
		} else if (q3.size () < n / 2) {
			q3.push (make_pair (a[idx][3], idx));
		} else return;		
		q2.push (make_pair (x, id));
	}	
}
void ins3 (ll x, ll id) {
	if (q3.size () < n / 2) q3.push (make_pair (x, id));
	else {
		pair <ll, ll> p = q3.top ();
		q3.pop ();
		ll idx = p.second;
		if (a[idx][1] > a[idx][2] && q1.size () < n / 2) {
			q1.push (make_pair (a[idx][1], idx));
		} else if (q2.size () < n / 2) {
			q2.push (make_pair (a[idx][2], idx));
		} else return;		
		q3.push (make_pair (x, id));
	}		
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);	
	cin >> T;
	while (T --) {
		while (! q1.empty ()) q1.pop ();
		while (! q2.empty ()) q2.pop ();
		while (! q3.empty ()) q3.pop ();
		cin >> n;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			ll x, y, z;
			if (q1.size () < n / 2) x = a[i][1];
			else {
				pair <ll, ll> p = q1.top ();
				ll idx = p.second;
				if (a[idx][2] > a[idx][3] && q2.size () < n / 2) {
					ll del = a[idx][2] - p.first;
					x = del + a[i][1];
				} else if (q3.size () < n / 2) {
					ll del = a[idx][3] - p.first;
					x = del + a[i][1];
				} else x = -inf;
			}
			if (q2.size () < n / 2) y = a[i][2];
			else {
				pair <ll, ll> p = q2.top ();
				ll idx = p.second;
				if (a[idx][1] > a[idx][3] && q1.size () < n / 2) {
					ll del = a[idx][1] - p.first;
					y = del + a[i][2];
				} else if (q3.size () < n / 2) {
					ll del = a[idx][3] - p.first;
					y = del + a[i][2];
				} else y = -inf;
			}		
			if (q3.size () < n / 2) z = a[i][3];
			else {
				pair <ll, ll> p = q3.top ();
				ll idx = p.second;
				if (a[idx][1] > a[idx][2] && q1.size () < n / 2) {
					ll del = a[idx][1] - p.first;
					z = del + a[i][3];
				} else if (q2.size () < n / 2) {
					ll del = a[idx][2] - p.first;
					z = del + a[i][3];
				} else z = -inf;
			}	
			if (x >= y && x >= z) {
				ins1 (a[i][1], i);
			} else if (y >= x && y >= z) {
				ins2 (a[i][2], i);
			} else if (z >= x && z >= y) {
				ins3 (a[i][3], i);
			}
		}
		ll res = 0;
		while (! q1.empty ()) {
			res += q1.top ().first;
			q1.pop ();
		}
		while (! q2.empty ()) {
			res += q2.top ().first;
			q2.pop ();
		}
		while (! q3.empty ()) {
			res += q3.top ().first;
			q3.pop ();
		}
		cout << res << '\n';		
	}
	return 0;
}
