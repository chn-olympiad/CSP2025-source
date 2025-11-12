#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
string s;
int n,m,c[505],ans,vis[15];
priority_queue<int>pq;
int jc(int x){
	int t = 1;
	for(int i = 1; i <= x; i ++){
		t *= i;
		t %= mod;
	}
	return t;
}
void dfs(int step,int out,int pass){
	if(step > n){
		if(pass >= m)ans ++;
		ans %= mod;
		return;
	}
	for(int i = 1; i <= n; i ++){
		if(vis[i])continue;
		if(s[step] == '1'){
			vis[i] = 1;
			if(c[i] <= out)dfs(step + 1,out + 1,pass);
			else dfs(step + 1,out,pass + 1);
			vis[i] = 0;
		}else{
			vis[i] = 1;
			dfs(step + 1,out + 1,pass);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s = " " + s;
	bool b = 1,one = 0;
	for(int i = 1; i <= n; i ++){
		if(s[i] == '0'){
			b = 0;
			break;
		}else one ++;
	}
	if(one < m){
		cout<<0;
		return 0;
	}
	int tr = n;
	for(int i = 1; i <= n; i ++){
		cin>>c[i];
		pq.push(c[i]);
		if(c[i] == 0)tr --;
	}
	if(b){
		if(tr >= m){
			cout<<jc(n);
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(m == n){
		if(tr != n){
			cout<<0;
			return 0;
		}
		int out = 0;
		for(int i = 1; i <= n; i ++){
			pq.pop();
			if(s[i] == '0')out ++;
			if(pq.top() <= out){
				cout<<0;
				return 0;
			}
		}
	}
	if(n <= 10){
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
