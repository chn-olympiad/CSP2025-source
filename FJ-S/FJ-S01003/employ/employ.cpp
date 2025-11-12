#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M=998244353;
ll n,m;
string s;
ll c[505],ans;

bool vis[505];

void dfs(int k,int sum,int b){
	//cout<<k<<" "<<sum<<" "<<b<<"\n"; 
	if(k>n){
		if(sum>=m) ans=(ans+1)%M;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(s[k-1]-'0'){
				if(c[i]<=b){
					dfs(k+1,sum,b+1);
				}else{
					dfs(k+1,sum+1,b);
				}
			}else{
				dfs(k+1,sum,b+1);
			}
			vis[i]=0;
		}
	}
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
