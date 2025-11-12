#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int a[N],n,m,vis[N];
string s;
int dfs(int k,int p,int r){
//	cout<<"dfs("<<k<<","<<p<<","<<r<<")";
	if(k==n){
//		cout<<" ["<<(n-r>=m)<<"]\n";
		return (n-r>=m);
	}
//	cout<<"\n";
	int t=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
//			cout<<"dfs("<<k<<","<<p<<","<<r<<") => ";
//			cout<<"dfs("<<k+1<<","<<i<<","<<r+(s[k+1]=='0'||r>=a[i])<<")\n";
			t+=dfs(k+1,i,r+(s[k+1]=='0'||r>=a[i]));
			vis[i]=0;
		}
	}
	return t;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="_"+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		bool flag=true;
		int ret=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') flag=false;
			ret=(1LL*ret*i)%mod;
		}
		if(flag) cout<<ret;
		else cout<<"0";
		return 0;
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		ret+=dfs(1,i,(s[1]=='0'));
		vis[i]=0;
	}
	cout<<ret;
	return 0;
} 
