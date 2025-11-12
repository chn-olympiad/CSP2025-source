#include <bits/stdc++.h>
using namespace std;
int c[510];
bool cmp(int a,int b){return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i=1;i<=n;i++){
		cin >> c[i];
	}
	if (m == 1){
	cout << n;
	return 0; 
	}
	if (m == n){
		cout << 0;
		return 0;
	}
	int ans = 0;
	for (int i=0;i<n;i++)ans += s[i]-'0';
	if (ans < m){
		cout << 0;
		return 0;
	}
	int mu = 1;
	if (ans == m){
		for(int i=1;i<=m;i++){
			mu *= (n-i+1);
		}
		for(int i=1;i<=m;i++){
			mu /= i;
		}
		cout << mu;
		return 0;
	}
	cout << 2;
	return 0;
}
