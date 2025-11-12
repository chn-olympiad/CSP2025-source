#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
const int N=900,mod=998244353;
int a[N],jc[N];
bool r[N];
int ans=0;
void dfs(int x,int al,int sum){
//	cout<<x<<' '<<al<<' '<<sum<<endl;
	if(x==n){
		if(sum>=m) ans++,ans%=mod;
		//cout<<ans<<endl;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!r[i]){
			r[i]=true;
		//	cout<<i<<endl;
			if(s[x]=='0'||al>=a[i]) dfs(x+1,al+1,sum);
			else if(s[x]=='1') dfs(x+1,al,sum+1); 
			r[i]=false;
		}
	}
	
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m>>s;
for(int i=1;i<=n;i++) cin>>a[i];
jc[0]=1;
for(int i=1;i<=n;i++){
	jc[i]=(jc[i-1]%mod*i%mod)%mod;
}
if(s.find('0')==-1){
	cout<<jc[s.size()]<<endl;
	return 0;
}
else if(n<=100){
	dfs(0,0,0);
	cout<<ans;
}
	
	
	
	return 0;
}
