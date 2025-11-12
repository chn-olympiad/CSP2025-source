#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[550],ans;
string s;
bool b[550];
void work1(){
	int sum=1;
	for(int i=1;i<=n;i++) sum=(sum*i)%mod;
	cout<<sum<<'\n';
} 
void work2(int cnt,int d){
	if(cnt==n+1) ans=(ans+1)%mod;
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		if(d>=c[i]) return;
		b[i]=true;
		work2(cnt+1,d+(s[cnt-1]=='0'));
		b[i]=false;
	} 
}
signed main(){
	std::ios::sync_with_stdio(0);
	freopen("employ1.in","r",stdin);
//	freopen("employ.out","w",stdin);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool flag=true;
	for(int i=0;i<n;i++)
		if(s[i]=='0') flag=false;
	if(flag) work1();
	else work2(1,0),cout<<ans<<'\n';
	return 0;
}
