#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[1000],b[1000];
bool flag=1;
long long ans;
const long long mod=998244353;
bool vis[1000];
int id[1000];
void dfs(int x){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=b[id[i]]){
				sum++;
				continue;
			}
			if(a[i]==1)continue;
			else{
				sum++;
			}
		}
		if(n-sum>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			id[x]=i;
			dfs(x+1);
			vis[i]=0;
		} 
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ4.in","r",stdin);
//	freopen("employ4.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
		if(a[i]==0)flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
