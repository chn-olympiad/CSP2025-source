#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
string s;
int ans(int n){
	long long t=1;
	for(int i=1;i<=n;i++){
		t*=i;
		t%=N;
	}
	return t;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>m;
	cout<<ans(n);
	return 0;
}
