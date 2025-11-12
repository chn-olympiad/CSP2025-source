//GZ-S00088 贵阳市第一中学 吴毅杰 
#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int MOD=998244353;
int c[N];
#define int long long
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s; 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=n;i>=1;i--){
		ans=(ans%MOD)*(i%MOD)%MOD; 
	}
	cout<<ans<<endl; 
	return 0;
}
