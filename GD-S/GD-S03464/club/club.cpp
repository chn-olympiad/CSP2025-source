#include<bits/stdc++.h>
using namespace std;
int n , m , ma , ans , t , _12;
struct node_1{
	int a , b , c;
}a[35];
struct node{
	int i , a , b , c , sum;
};
queue<node> q;
bool cmp(node_1 x , node_1 y){
	return x.a > y.a;
}
void bfs(){
	q.push({1 , 0 , 0 , 0 , 0});
	while(!q.empty()){
		node b = q.front();
		q.pop();
		if(b.i > n){
			ans = max(ans , b.sum);
			continue;
		}
		if(b.a + 1 <= ma){
			q.push({b.i + 1 , b.a + 1 , b.b , b.c , b.sum + a[b.i].a});
		}
		if(b.b + 1 <= ma){
			q.push({b.i + 1 , b.a , b.b + 1 , b.c , b.sum + a[b.i].b});
		}
		if(b.c + 1 <= ma){
			q.push({b.i + 1 , b.a , b.b , b.c + 1 , b.sum + a[b.i].c});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		cin >> n;
		_12 = 1 , ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(a[i].b != 0 || a[i].c != 0){
				_12 = 0;
			}
		}
		ma = n / 2;
		if(_12){
			sort(a + 1 , a + n + 1 , cmp);
			for(int i = 1; i <= ma; i++){
				ans += a[i].a;
			}
			cout << ans;
			continue;
		}
		bfs();
		cout << ans << "\n"; 
	}
	return 0;
}

