#include<iostream>
#include<stack>
using namespace std;
int n,m,ans = 0;
string s;
int c[501];
stack<int> t,t1;
void check(){
	while(!t.empty()){
		t1.push(t.top());
		t.pop();
	}
	int v = 0,u = 0;
	for(int i = 1; i <= n; i++){
		if(u >= t1.top()){
			t1.pop();
			continue;
		}
		else if(s[i-1] == '0') u++;
		else v++;
	}
	if(v >= m) ans++;
	return;
}
void dfs(int x,int y){
	if(x > n){
		check();
		return;
	}
	for(int i = y+1; i <= n; i++){
		t.push(c[i]);
		dfs(x+1,i);
		t.pop();
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool b = true;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(s[i-1] == '0') b = false;
	}
	if(b){
		ans = 1;
		for(int i = n; i > 1; i--){
			ans *= i;
			ans = ans % 998244353;
		}
		cout << ans;
	}
	else{
		dfs(0,0);
		cout << ans;
	}
	return 0;
} 
