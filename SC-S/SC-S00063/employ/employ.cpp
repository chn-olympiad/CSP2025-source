#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353ll;
	}
	cout<<ans;
	return 0;
}