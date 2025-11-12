#include <bits/stdc++.h>
#define ll long long
constexpr int N = 1e6 + 5;
using namespace std;
struct node{
	int a,b,c;
}qwq[N];
int e[N][4];
int T,n,ans = 0,t[N],tot=0,l;
void dfs(int now,int x,int a,int b,int c){
	if(a > l || b > l || c > l) return;
	if(x >= n + 1){
//		cout << a <<" " << b <<" " <<c <<" " << ans <<"\n";
		ans = max(ans , now);
		return;
	}
	for(int i = 1 ; i <= 3; i ++){
		if(i == 1) dfs(now + e[x][i] , x + 1 , a + 1 , b , c);
		else if(i == 2) dfs(now + e[x][i] , x + 1 , a , b + 1, c);
		else dfs(now + e[x][i] , x + 1 , a , b , c + 1);
	}
}
void except_20pts(){
	for(int i = 1 ; i <= 3; i ++){
		if(i == 1) dfs(e[1][i] , 2 , 1 , 0 , 0);
		else if(i == 2) dfs(e[1][i] , 2 , 0 , 1 , 0);
		else dfs(e[1][i] , 2 , 0 , 0 , 1);
	}
	cout << ans << '\n';
}
bool cmp(int x,int y){
	return x > y;
}
bool cmp2(node x,node y){
	return x.a - x.b + y.b - y.a > 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = 0;
		l = n >> 1;
		bool f2 = 1 , f3 = 1;
		int z = 0;
		for(int i = 1 ; i <= n ; i ++){
			cin >> e[i][1] >> e[i][2] >> e[i][3];
			z += max(e[i][1] , max(e[i][2] , e[i][3])); 
//			qwq[i] = (node){e[i][1] , e[i][2] , e[i][3]};
			if(e[i][2] != 0) f2 = 0;
			if(e[i][3] != 0) f3 = 0;
		}
		if(n <= 30){
			except_20pts();
			continue;
		}
		if(f3 && f2){
			for(int i = 1 ; i <= n ; i++){
				t[i] = e[i][1];
			}
			sort(t + 1 , t + n + 1, cmp);
			for(int i = 1 ; i <= l ; i++) ans += t[i];
			cout << ans <<'\n';
			continue;
		}
		cout << z << '\n';
//		sort(qwq + 1, qwq + n + 1, cmp2);
//		for(int i = 1 ; i <= n ; i ++){
//			ans += max(qwq[i].a , qwq[i].b);
//		}
//		cout << ans << '\n'; 
	}
	return 0;
} 
