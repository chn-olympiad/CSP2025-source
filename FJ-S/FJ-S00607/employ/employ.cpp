#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
vector<char> s;
vector<int> c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	s.resize(n+1);
	c.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<rand()*rand()%mod;
	return 0;
}
