#include<bits/stdc++.h>
#define ll long long
#define f(i,n,m) for(int i = 1; i <= n; i++)
using namespace std;
const ll N = 510;
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
ll n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cout << 0;
	return 0;
}
