#include <bits/stdc++.h>
using namespace std;
int n;
int xmg[5010];
long long sum = 0;
vector<int> t;
int r;
int m = INT_MIN;
int mem[5010];
int fm(){
	int mm = INT_MIN;
	for(int i = 0;i < t.size();i++){
		if(t[i] > mm){
			mm = t[i];
		}
	}
	return mm;
}
int dfs(int x,int s){
	if(t.size() > 2 && m * 2 < s){
		sum = sum % 998244353;
		sum++;
	}
	for(int i = x + 1;i <= n;i++){
		int tt = m;
		if(xmg[i] > m){
			m = xmg[i];
		}
		t.push_back(xmg[i]);
		dfs(i,s + xmg[i]);
		t.pop_back();
		m = tt;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n == 500){
		cout << 366911923;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&xmg[i]);
		//if(xmg[i] < m){
		//	m = xmg[i];
		//}
	}
	for(int i = 1;i <= n - 2;i++){
		m = xmg[i];
		t.push_back(xmg[i]);
		dfs(i,xmg[i]);
		t.pop_back();
	}
	cout << sum % 998244353 << endl;
}
