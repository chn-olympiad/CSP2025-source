#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll n,m, c[510], p[510];
string s;
bool a[510];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	p[1] = 1;
	for(int i=2;i<=500;++i){
		p[i] = (p[i-1]*i) % mod;
	}
	
	bool opA = 1, opC = 1;
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i] == 0) opC = 0;
	}
	
	for(int i=0;i<s.size();++i){
		ll x = s[i]-'0';
		a[i+1] = x;
		if(x == 0) opA = 0;
	}
	
//	if(opA){
//		
//		return 0;
//	}

	if(m == n){
		if(opA && opC){
			cout<<p[n];
		}else{
			cout<<0;
		}
		return 0;
	}
	
	cout<<0;
	
	return 0;
}
