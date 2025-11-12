#include<bits/stdc++.h>
using namespace std;
int n,ans,sum,mx;
int a[5007];
bool vis[5007];
void dfs(int x,int nsm,int lmx,int m,int j){
	if(x>=m){
		if(nsm>lmx*2){
			ans++;
			ans%=998244353;
		}	
		return ;	
	}
	else{
		for(int i=j+1;i<=n;i++){
			dfs(x+1,nsm+a[i],max(lmx,a[i]),m,i);
		}
	}
	return ;
}

int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(sum>mx*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		for(int i=3;i<=n;i++){//m
			dfs(0,0,0,i,0);
		}		 
		cout<<ans;
	}
	return 0;
}
