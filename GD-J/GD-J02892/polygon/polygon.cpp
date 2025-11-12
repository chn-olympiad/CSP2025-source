#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
int n,a[500010],ans;
bool vis[500010];
void dfs(int x,int sum,int mx){
	if(sum>mx*2){
		ans=((ans+1)%Mod);
	}
	if(x>n) return;
	for(int i=x;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(i+1,sum+a[i],max(mx,a[i]));
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%Mod;
} 
//sto CCF orz
//Give me 1=


