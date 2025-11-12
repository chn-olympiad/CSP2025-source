#include<bits/stdc++.h>
#define ll long long
#define f(i,n,m) for(int i = 1; i <= n; i++)
using namespace std;
const ll N = 1e5*2+1;
ll rd(){
	ll x, f = 1;
	char s;
	s = getchar();
	if(s == '-') f = -1, x = 0;
	else x=s-'0';
	while(1){
		s = getchar();
		if(s < '0' || s > '9') return x*f;
		x*=10, x+=s-'0';
	}
}
ll n, k;
string s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = rd(), k = rd();
	string x, y;
	for(int i = 1; i <= n; i++) cin >> s[i];
	while(k--){
		cin >> x >> y;
		for(int i = 1; i <= n; i++){
			
		}
		cout << 0;
	}
	return 0;
}
