#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;cin>>st;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(cnt>=x)cnt++;
	} 
	long long ans=1;
	for(long long i=2;i<=n-cnt;i++){
		ans*=i;ans%=MOD;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 
