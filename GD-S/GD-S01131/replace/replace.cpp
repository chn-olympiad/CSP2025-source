#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int n, q; 
string o[N], o1[N];
//库里库里 库库里 
void solve1(){
	for(int i=1; i<=n; i++){
		string a, b; cin >> a >> b;
		o[i] = a; o1[i] = b;
	}
	string x, y; cin >> x >> y;
	int t = 0;
	for(int i=0; i<x.size(); i++){
		if(x[i] != y[i]){
			t++;
			if(i == 0) continue;
			if(x[i-1] != y[i-1]) t--;
		}
	} 
	if(t>=2){
		cout << '0';
		return ;
	}
	int s, s1;
	for(int i=0; i<x.size(); i++){
		if(i == 0 && x[i] != y[i]) s = 0;
		else if(i == 0) continue;
		else if(x[i] != y[i] && x[i-1] == y[i-1]){
			s = i;
		}
		else if(x[i] == y[i] && x[i-1] == y[i-1]){
			s1 = i - 1;
		}
	}
	int cnt = 0;
	string a2 = x.substr(s, s1 - s + 1), a3 = y.substr(s, s1 - s + 1);
	for(int i=1; i<=n; i++){
		string a = o[i], b = o1[i];
		for(int j=0; j<a.size(); i++){
			if(j + s1 - s > a.size()) break;
			if(a.substr(j, s1 - s + 1) == a2){
				if(b.substr(j, s1 - s + 1) == a3){
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	if(q == 1){
		solve1();
		return 0;
	}
	
	
	return 0;
}
//这就是我们的库里 
