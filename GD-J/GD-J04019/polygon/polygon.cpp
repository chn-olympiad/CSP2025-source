#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
const int MOD=998244353;
vector<int>a(N);
vector<int>b(N);
vector<int>tmp(N);
vector<bool>vis(N);
int n,idx=0;
int sigama(){
	int r=0;
	for(auto i:tmp){
		r+=tmp[i];
	}
	return r;
	
}
int mx(){
	int r=0;
	for(auto i:tmp){
		r=max(r,tmp[i]);
	}
	return 2*r;
	
}
int ans=0;
void dfs(){
	if(idx>=3&&idx<=n){
		if(sigama()>mx()){
//			cout<<sigama<<" "<<mx<<endl;
			ans++;
			for(auto v:tmp){
//				cout<<v<<" "<<endl;
				if(!v)break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(idx>n)return;
		tmp[++idx]=a[i];
		vis[i]=1;
		dfs();
		tmp[--idx]=0;
		vis[i]=0;
	}
	
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs();
	cout<<ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
