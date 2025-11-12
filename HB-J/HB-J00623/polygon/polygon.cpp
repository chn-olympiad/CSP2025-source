#include <bits/stdc++.h>
using namespace std;
int book[5009];
int b[5009];
long long n;
long long cnt = 0;
map < string , int > mp;
void dfs(int p , int sumn , int maxn , string s){
//	cout << s << " " << sumn << " " << maxn << "\n";
	if(p > 3 && sumn != 0 && sumn > 2 * maxn && mp[s] == 0){
			cnt++;
			mp[s] = 1;
	}
	if(p == n + 1 || b[p] == 1) return ;
	dfs(p + 1 , sumn , maxn , s);
	if(book[p] > maxn) maxn = book[p];
	dfs(p + 1 , sumn + book[p] , maxn , s + to_string(p));
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
//	int t = time(0);
	cin >> n;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		cin >> book[i];
//		cout << book[i] << " ";
		if(book[i] != 1) flag = false;
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(flag){
		cout << n * (n + 1) / 2;
		return 0;
	}
	dfs(1 , 0 , 0 , "");
//	int t1 = time(0);
	cout << cnt;
//	cout << "\n" << t1 - t;
	return 0;
}
