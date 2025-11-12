#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,v[1000005],no[1000005];
string g;
//void can(){
//	int uke=0;
//	for(int j=1;j<=n;j++){
//		int i=f[j];
//		//cout<<i<<' ';
//		if(uke>=v[i]||g[j-1]=='0'){
//			uke++;
//		}
//	}//cout<<endl;,cout<<"YES\n"
//	if(uke<=n-m)ans++,ans=(ans>=998244353?ans-998244353:ans);
//	return;
//}
inline void dfs(int x,int uke){
//	cout<<x<<' '<<uke<<endl;
	if(x==n+1){
//		cout<<uke<<"  ";
//		for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
		ans+=(uke<=n-m);
		return;
	}
	if(uke>n-m)return;
	for(int i=1;i<=n;i++){
		if(no[i])continue;
		no[i]=1;
		dfs(x+1,uke+(uke>=v[i]||g[x-1]=='0'));
		no[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>g;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

