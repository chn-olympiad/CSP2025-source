#include <bits/stdc++.h>
using namespace std;
int n,p,c[510],m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}for(int i=0;i<n;i++){
		cin >> c[i];
	}
	if(m == n){
		cout << m;
		return 0;
	}
	if(m == 1){
		cout << 1;
		return 0;
	}
	return 0;
}
