#include<bits/stdc++.h>
using namespace std;
int n,x,sum=1;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	cin >> s;
	bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') flag=0;
	} 
	for(int i=1;i<=n;i++) cin >> x;
	while(n){
		sum*=n;
		sum%=998244353;
		n--;
	}
	if(flag) cout << sum;
	else cout << 0;
	return 0;
}
