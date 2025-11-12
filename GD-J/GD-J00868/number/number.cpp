#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.length() - 1,tmp = 0;
	for(int i = 0;i<=n;i++){
		if(48 <= int(s[i]) && int(s[i]) <= 57){
			a[++tmp] = int(s[i] - 48);
		}
	}
	sort(a+1,a+tmp+1);
	for(int i = tmp;i>=1;i--){
		cout << a[i];
	}
} 
