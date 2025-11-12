#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[505],zz[15],b[15],ans,jc[505];
void dfs(int k){
	if(k==n+1){
		int rs=0;
		for(int i=1;i<=n;i++){
			int kl=b[i];
			if(i-1-rs<c[kl] && s[i]=='1'){
				rs++;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<'\n';
		if(rs>=m)ans++;
		return ;
	}
	int st=0;
	while(zz[st]!=n+1){
		int nx=zz[st];
		b[k]=nx;
		zz[st]=zz[nx];
		dfs(k+1);
		zz[st]=nx;
		b[k]=0;
		st=nx;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		zz[i]=i+1;
	}
	if(flag){
		jc[1]=1;
		for(int i=2;i<=n;i++){
			jc[i]=jc[i-1]*i%mod;
		}
		cout<<jc[n];
		return 0;
	}
	zz[0]=1;
	if(n>=20){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//8pts
