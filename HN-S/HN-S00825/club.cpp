#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int t, n, a, b, c, sum;
struct node{
	int x, y, z;
}p[100005];
int pan(int i){
	if(p[i].x >= p[i].y && p[i].x >= p[i].z){
		return 1;
	}
	if(p[i].y >= p[i].x && p[i].y >= p[i].z){
		return 2;
	}
	if(p[i].z >= p[i].x && p[i].z >= p[i].y){
		return 3;
	}
}
int get(int i){
	int maxx, minx, midx;
	maxx = max({p[i].x, p[i].y, p[i].z}), minx = min({p[i].x, p[i].y, p[i].z}), midx = p[i].x + p[i].y + p[i].z - maxx - minx;
	return maxx - midx;
}
void work(){
	cin >> n;
	a = b = c = sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> p[i].x >> p[i].y >> p[i].z;
		a += (pan(i) == 1), b += (pan(i) == 2), c += (pan(i) == 3);
		sum += max({p[i].x, p[i].y, p[i].z});
	}
	priority_queue<int, vector<int>, greater<int> > q;
	while(!q.empty()){
		q.pop(); 
	}
	if(a > n / 2){
		for(int i = 1; i <= n; i++){
			if(pan(i) == 1){
				q.push(get(i));
			}
		}
		while(a > n / 2){
		 	sum -= q.top(), a--;
			q.pop(); 
		} 
	}
	else if(b > n / 2){
		for(int i = 1; i <= n; i++){
			if(pan(i) == 2){
				q.push(get(i));
			}
		}
		while(b > n / 2){
		 	sum -= q.top(), b--;
			q.pop(); 
		} 
	}
	else if(c > n / 2){
		for(int i = 1; i <= n; i++){
			if(pan(i) == 3){
				q.push(get(i));
			}
		}
		while(c > n / 2){
		 	sum -= q.top(), c--;
			q.pop(); 
		}
	}
	else{
		cout << sum << "\n";
		return;
	}
	cout << sum << "\n";
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		work();
	}
	return 0;
}
