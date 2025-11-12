#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3;
const int mod=998244353;
int n,m;
string s;
int c[N];
int ans;
int C(int x,int y){
	int sum1=1,sum2=1;
	for(int i=x;i>x-y;i--) sum1*=i;
	for(int i=y;i>=1;i--) sum2*=i;
	return sum1/sum2;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=m;i<=n;i++){
		ans+=C(n,i)%mod;
		ans=ans%mod;
	}
	cout<<ans;
	return 0;
}
