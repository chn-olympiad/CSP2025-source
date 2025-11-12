#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[5005][10500],ans,sum;
void dfs(int x,int y){
	if(x>n){
		if(y==k) ans=max(x,ans);
		return ;
	}
	if(y==k){
		ans=max(x,ans);
	}
	for(int i=1;i<=n;i++){
		dfs(x+1,y^a[i]);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0||a[i]!=1){
			u=1;
		}
		if(a[i]==1){
			sum++;
		}
	}
	if(sum==n){
		if(sum%2==0){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	int sss=0;
	int man=0,y=0;
	if(u==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				man=man^a[j];
				if(man==k&&y==0){
					y=j;
				}
				if(man==k){
					sss=j-y;
				}
			}
			if(man==k){
				cout<<n-i+1;
				return 0;
			}
		}
		cout<<sss;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[5005][10500],ans;
int main(){	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=k;j>=1;j--){
			f[i][j]=f[i-1][j];
			if(j-a[i]^j>=0){
				f[i][j]=f[i-1][j-a[i]^a[i-1]]+1;
			}
		}
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,f[i][k]);
	}
	cout<<ans;
	return 0;
}*/
