#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,a[20000800],sum[20000800],p[5008][5008];
string s;
void dfs(int x,long long l){
	if(x==n+1){
		ans=max(ans,l);
	}
	else{
		for(int i=x;i<=n;i++){
			if(p[x][i]==k){
				dfs(i+1,l+1); 
			}
		}	
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int pd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) pd=1;
		sum[i]=sum[i-1]^a[i];
	}
	if(pd==0){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++){
			p[i][j]=sum[j]^sum[i-1];
		}
	}
	dfs(1,0);
	cout<<ans;
}
