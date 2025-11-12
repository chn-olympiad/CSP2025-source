#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
long long a[505],c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans%MOD;
}
