#include<bits/stdc++.h>
#define int long long
const int N=5e6+5;
using namespace std;
string s;
char c[N];
int n,lt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.size();
	s = "?" + s;
	for(int i=1;i<=n;i++){
		if(s[i] >='0' && s[i] <= '9'){
			c[++lt] = s[i];
		}
	}
	sort(c+1,c+1+lt);
	for(int i=lt;i>-1;i--){
		cout<<c[i];
	}
	return 0;
}

// Why do the stars shine so bright in sky
