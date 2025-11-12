#include<bits/stdc++.h>
using namespace std;

struct ssss{
	int a;
	int b;
	int c;
	
	int maxx;
	
};

ssss a[100005];
int vis1;
int vis2;
int vis3;

int cmp(ssss a, ssss b){
	if(a.a != b.a){
		return a.a < b.a;
	}else if(a.b != b.b){
		return a.b < b.b;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int ans = 0;
		vis1 = 0;
		vis2 = 0;
		vis3 = 0;
		
		for(int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;		
			a[i].maxx = max(max(a[i].a, a[i].b), a[i].c);
			ans += a[i].maxx;
			
			if(a[i].maxx == a[i].a){
				vis1++;
			}
			if(a[i].maxx == a[i].b){
				vis2++;
			}
			if(a[i].maxx == a[i].c){
				vis3++;
			}
			
		}
			
		priority_queue<int>q;
		if(vis1 > n / 2){
			int asd = vis1 - n / 2;
			for(int i = 1; i <= n; i++){
				if(a[i].a == a[i].maxx){
					q.push(max(a[i].b - a[i].a, a[i].c - a[i].a));
				}
			}
			for(int i = 1; i <= asd; i++){
				ans += q.top();
				q.pop();
			}
		}
		if(vis2 > n / 2){
			int asd = vis2 - n / 2;
			for(int i = 1; i <= n; i++){
				if(a[i].b == a[i].maxx){
					q.push(max(a[i].a - a[i].b, a[i].c - a[i].b));
				}
			}
			for(int i = 1; i <= asd; i++){
				ans += q.top();
				q.pop();
			}
		}
		if(vis3 > n / 2){
			int asd = vis3 - n / 2;
			for(int i = 1; i <= n; i++){
				if(a[i].c == a[i].maxx){
					q.push(max(a[i].a - a[i].c, a[i].b - a[i].c));
				}
			}
			for(int i = 1; i <= asd; i++){
				ans += q.top();
				q.pop();
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
