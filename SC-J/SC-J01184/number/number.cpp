#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long ll;
string s;
ll a[11];

void solve(){
	cin >> s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(ll j=1;j<=a[i];j++) cout << i;
	}
	cout << '\n';
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}