#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[514],ct=0,a[514];
const ll mod=998244353;
string s;
ll an;
void sol(){
	int giv=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			giv++;
		}else{
			if(giv>=c[a[i]]) giv++;
		}
		if(i-giv>=m){
			an++;
			return;
		}
	}
	if(n-giv>=m) an++;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s; s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') ct++;
	}
	if(ct<m){
		cout<<0;
		return 0;
	}
	ct=n;
	for(int i=1;i<=n;i++){
		cin>>c[i]; if(c[i]==0) ct--;
	}
	if(ct<m){
		cout<<0;
		return 0;
	}
	if(n==m){
		an=1;
		for(int i=1;i<=n;i++){
			an*=i;
			an%=mod;
		}
		cout<<an;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	sol();
	while(next_permutation(a+1,a+n+1)) sol();
	cout<<an;
	return 0;
}
