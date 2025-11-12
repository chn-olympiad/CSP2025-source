#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n , l[N][5];
int dfs(int id , int a , int b , int c , int num){
	if(id > n) return num;
	int a1 , b1 , c1;
	a1 = b1 = c1 = 0;
	if(a) a1 = dfs(id+1,a-1,b,c,num+l[id][1]);
	if(b) b1 = dfs(id+1,a,b-1,c,num+l[id][2]);
	if(c) c1 = dfs(id+1,a,b,c-1,num+l[id][3]);
	return max(a1,max(b1,c1));
}
void solve(){
	cin >> n;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin >> l[i][1] >> l[i][2] >> l[i][3];
		if(l[i][2] != 0) f = 0;
	}
	if(f){
		priority_queue<int> q;
		for(int i = 1;i <= n;i++) q.push(l[i][1]);
		int ans = 0 , x = n / 2;
		while(x--){
			ans += q.top();
			q.pop();
		}
		cout << ans << endl;
	}else cout << dfs(1,n/2,n/2,n/2,0) << endl;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= 3;j++)
			l[i][j] = 0;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int t;
	scanf("%d" , &t);
	while(t--) solve();

	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
