#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	long long ret=1,mod=998244353;
	for(int i=2;i<=n;i++){
		ret*=i;
		ret%=mod;
	}
	cout<<ret;
	return 0;
}
