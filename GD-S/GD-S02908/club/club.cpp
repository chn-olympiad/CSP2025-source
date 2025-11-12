#include<bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;

struct node{
	int x, y, z, ca;
}a[N];

priority_queue<int, vector<int>, greater<int> > c1;
priority_queue<int, vector<int>, greater<int> > c2;
priority_queue<int, vector<int>, greater<int> > c3;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		while(!c1.empty()){
			c1.pop();
		}
		while(!c2.empty()){
			c2.pop();
		}
		while(!c3.empty()){
			c3.pop();
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				a[i].ca = min(abs(a[i].x - a[i].y), abs(a[i].x - a[i].z));
				ans += a[i].x;
				c1.push(a[i].ca);
			}
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				a[i].ca = min(abs(a[i].y - a[i].x), abs(a[i].y - a[i].z));
				ans += a[i].y;
				c2.push(a[i].ca);
			}
			else if(a[i].z >= a[i].y && a[i].z >= a[i].x){
				a[i].ca = min(abs(a[i].z - a[i].x), abs(a[i].z - a[i].y));
				ans += a[i].z;
				c3.push(a[i].ca);
			}
		}
		int mn = n / 2;
		while(c1.size() > mn){
			int v = c1.top();
			ans -= v;
			c1.pop();
		}
		while(c2.size() > mn){
			int v = c2.top();
			ans -= v;
			c2.pop();
		}
		while(c3.size() > mn){
			int v = c3.top();
			ans -= v;
			c3.pop();
		}
		cout << ans << '\n';
	}
	return 0;
} 
