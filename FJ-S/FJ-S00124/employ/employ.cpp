#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	cout<<n*m%998244353;
	return 0;
}
