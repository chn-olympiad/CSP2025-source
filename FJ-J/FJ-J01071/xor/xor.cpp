#include <bits/stdc++.h>
using namespace std;
int a[500005],ans=0,n,k;
void dfs(int i,int cnt,int sum){
	if(i==n){
		if(cnt==k){
			ans=max(ans,sum+1);
		}else{
			ans=max(ans,sum);
		}
		return;
	}
	if(cnt==k){
		dfs(i+1,a[i+1],sum+1);
		dfs(i+1,0,sum+1);
	}else{
		dfs(i+1,cnt^a[i+1],sum);
		dfs(i+1,cnt,sum);
	}
}
void dfs0(int i,int cnt,int sum){
	if(i==n){
		if(cnt==k){
			ans=max(ans,sum+1);
		}else{
			ans=max(ans,sum);
		}
		return;
	}
	if(cnt==k){
		for(int j=i+1;j<=n;j++){
			dfs0(j,a[j],sum+1);
		}
	}else{
		dfs0(i+1,cnt^a[i+1],sum);
		dfs0(i+1,cnt,sum);
	}	
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int pf=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			pf=true;
		}
	}
	if(pf==false){
		if(k==0){
			int ans=n/2;
			cout<<ans;
			return 0;
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			dfs0(i,a[i],0);
		}
	}else{
		dfs(1,a[1],0);
		dfs(1,0,0);
	}
	cout<<ans<<endl;
	
	return 0;
}
