#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>s;
	bool p=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	for(int i=0;i<n;i++) {
		if(s[i]!=1) p=1;
	}
	if(p==0) {
		long long ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%N;
		cout<<ans<<endl;
	}else cout<<0<<endl;
	return 0;
}
