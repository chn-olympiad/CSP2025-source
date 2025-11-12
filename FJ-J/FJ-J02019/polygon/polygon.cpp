#include<bits/stdc++.h>
using namespace std;

long long ans,n;
const long long Mod=998244353;
int a[5010];
bool vis[5010];
int i; 
void dfs(int deep,long long sum,int mx,int last){
	if(deep==i){
		if(sum>mx*2){
			ans++;
		}
		return;
	}
	for(int i=last;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int mxa=max(mx,a[i]);
			dfs(deep+1,sum+a[i],mxa,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=3;i<=n;i++){
		string s;
		dfs(1,0,0,1);
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}

