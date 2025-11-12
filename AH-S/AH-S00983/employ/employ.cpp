#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
const int mod=998244353;
int c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
