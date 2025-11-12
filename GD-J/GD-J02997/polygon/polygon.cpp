#include <bits/stdc++.h>
#include <cstdio>
#define ull unsigned long long
#define MOD 998244353 
using namespace std;

int n, a[5005];
//stack<short> stk;
//stack<short> s2;

//void printstk(){
//	while(!stk.empty()){
//		s2.push(stk.top());
//		stk.pop();
//	}
//	while(!s2.empty()){
//		cout << s2.top() << " ";
//		stk.push(s2.top());
//		s2.pop();
//	}
//	cout << endl;
//}

int dfs(short p, ull s, short chosen){
	ull res = 0;
//	stk.push(p);
	if(p == n && chosen >= 3 && s > a[p]){
//		printf("chosen = %d\n", chosen);
//		printstk();
//		stk.pop();
		return 1;
	}
	for(int i=p+1; i<=n; i++){
		res += dfs(i,s+a[p],chosen+1) % MOD;
	}
	if(s > a[p] && chosen >= 3){
//		printf("chosen = %d\n", chosen);
//		printstk();
		res++;
	}
//	stk.pop();
	return res % MOD;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	cout << dfs(0,0,0) % MOD; //NO TLE or MLE pls!!! 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
