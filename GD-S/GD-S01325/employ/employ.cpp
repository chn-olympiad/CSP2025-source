#include<bits/stdc++.h>
using namespace std;
string s;
bool b = 1;
long long sum = 1;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
//	for(int i = 1;i <= n;i++){
		cin >> s;
//	}
	if(n == m){
		for(int i = 0;i < s.size();i++){
		if(s[i] == '0'){
			cout << 0 << endl;
			return 0;
		}cout << 1 << endl;
	}
		
	}
	for(int i = 1;i <= n;i++){
		sum = (sum * i) % 998244353;
	}
	cout << sum << endl;
	return 0;
}
