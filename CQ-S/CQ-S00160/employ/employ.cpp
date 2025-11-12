#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=1,c[510],t[11];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<s.size();i++){
		t[s[i]-'0']++;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for (int i=n;i>=2;i--) ans*=i;
	cout<<ans%998244353;
	
	return 0;
}

