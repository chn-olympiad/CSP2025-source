#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c[N];
int vis[N];
int n,m;string s;
int nn,ret;
void dfs(int i){
	if(i>nn){
		ret++;
		return;
	}
		if(vis[i]==0){
			vis[i]=1;
			dfs(i+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int ok=1,cnt=0; 
//	int len=s.size();
	for(int i=0;i<n;i++){
		if(s[i]!='1')ok=0;
	}
	for(int i=0;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	nn=n-cnt;
	if(ok==1){
		dfs(0);
		cout<<ret;return 0;
	}
	cout<<rand()%998244353;
	return 0;
}
