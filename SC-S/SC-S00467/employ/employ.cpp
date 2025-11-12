#include<bits/stdc++.h>
using namespace std;
#define filename "employ"
const int N=1e5+2,mod=998244353;
int n,m,a[N];
long long ans;
string s;

int main(){
#ifdef filename
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int cnt=0;
		for(;cnt<n;cnt++) if(s[cnt]=='1') break;
		cout<<cnt<<" LXH \n";
		long long res=1;
		for(long long i=2;i<n;i++) (res*=i)%=mod;
		for(int i=1;i<=n;i++) if(cnt<a[i]) (ans+=res)%=mod;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}