#include<bits/stdc++.h>
using namespace std;
const int maxn=505,mod=998244353;

long long n,m,c[maxn],ans;
string s;
int a[maxn];
bool vis[maxn];

void work(){
	int last=1;
	int tot=n;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			last=i+1;
		}else{ 
			if(c[a[i]]<=i-last){
				tot--;
			}
		}
	}
	cout<<tot<<'\n';
	ans+=(tot>=m);
	return; 
}

void dfs(int step){
	if(step>n){
		work();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
1 0 1
1 1 2
*/ 
