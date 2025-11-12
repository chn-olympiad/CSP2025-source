#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n, m,num = 1;
	cin >> n>>m;
	string s;
	cin >> s;
	int c[n+1];
	for(int i =1;i<=n;i++){
		cin >> c[i];
	}
	if(m == 1){
		if(s[0]=='0'){
			cout << n;
			return 0;
		}
	}
	else if(n == m){
		cout << 1;
		return 0;
	} 
	else{
		for(int i = 1;i <= m;i++){
			num*=n;
			n--;
			num%998244353;
		}
	}
	cout <<num;
	return 0;
}
