#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
int a[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int g=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&'9'>=s[i]){
			g++;
			a[g]=s[i]-48;
		}
	}
	sort(a+1,a+1+g);
	for(int i=g;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 