#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f,f1,maxn;
void dfs(int x,int ans){
	if(n-x+1+ans<=maxn) return ;
	if(x>=n+1){
		maxn=max(maxn,ans);
		return ;
	}
	int tx=0;
	for(int i=x;i<=n;i++){
		tx=tx^a[i];
		if(tx==k) {
			dfs(i+1,ans+1);
		} 
		else dfs(i+1,ans);	
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]>=2) f1=1;
	} 
	if(f==0){
		if(k>=2) cout<<0;
		if(k==1) cout<<n;
		if(k==0) cout<<n/2;
		return 0;
	}
	if(f1==0){
		if(k>=2) cout<<0;
		if(k==1) {
			int ans=0;
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans;
		}
		if(k==0){
			int ans=0;
			f1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					f1=0;
				}
				if(a[i]==1) {
					f1++;
					if(f1==2) {
						ans++;
						f1=0;
					}
				}
			}
			cout<<ans;
		}
		return 0;
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}
