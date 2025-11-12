#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const ll mod=998244353;
int n,m,c[N];
bool P[N],vis[N];
ll f[N],ans=0;
void dfs(int day,int tot){
	if(day>n)
		return ;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(day-tot-1>=c[i]||!P[i])
				dfs(day+1,tot);
			else{
				if(tot+1==m){
					ans=(ans+f[n-day])%mod;
					return;
				}		
				dfs(day+1,tot+1);
			}
		}
		vis[i]=0;
	}
	return ;
}
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=500;i++){
		f[i]=f[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++)	
		scanf("%1d",&P[i]);
	int x=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)
			x--;
	}
		
	if(n<20){
		dfs(1,0);
		cout<<ans;
	}
	else{		
		cout<<f[x];	
	}
	return 0;
}
