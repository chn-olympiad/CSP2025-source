#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m,a[505],vis[505],sum,ans,j;string s;
void dfs(int k){
	if(k>n){
		if(sum>=m)ans++,ans%=mod;
		//cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int f=0; 
			if(j>=a[i]||s[k-1]=='0'){
				j++;f=1;
				//cout<<1;
			}
			else{
			//	cout<<1;
				sum++;
			}
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
			if(f==1){
				j--;
			}
			else{
				sum--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int f=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0')f=0;
	}
	if(f==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
