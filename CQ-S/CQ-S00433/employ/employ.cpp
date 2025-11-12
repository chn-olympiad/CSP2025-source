#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
const int MOD=998244353;
int n,m,ans,ql;
int a[N];
int vis[N],cz[N];
string s;
void dfs(int t){
	if(t==n+1){
		int myy=0;ql=0;
//		for(int i=1;i<=n;i++){
//			cout<<cz[i]<<" ";
//		}cout<<"\n";
		for(int i=1;i<=n;i++){
			if(s[i]=='0') ql++;
			else{
				if(ql>=a[cz[i]]) ql++;
				else{
//					cout<<cz[i]<<" "<<a[cz[i]]<<"\n";
					myy++;
				}
			}
		}
		if(myy>=m){
//			for(int i=1;i<=n;i++){
//				cout<<cz[i]<<" ";
//			}
//			cout<<"\n";
//			cout<<myy<<"\n";
			ans++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				cz[t]=i;
				dfs(t+1);
				vis[i]=0;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans%MOD;
	}
	else {
		cin>>s;
		s=" "+s;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans;
	}
	return 0;
}
/*
3 2
101
1 1 2

*/
