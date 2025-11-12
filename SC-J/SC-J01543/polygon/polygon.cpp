#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],s[10010],vis[10010],ans,mod=998244353;
void dfs(int m){
	if(m>=4){
		long long sum=0,mx=0,shi=0;
		//cout<<m-1<<endl;
		for(int i=1;i<=m-1;i++){
			
			sum+=s[i];
			mx=max(s[i],mx);
			//cout<<s[i]<<" ";
		}
		//	cout<<endl;
		
	//	cout<<endl;
		if(sum>mx*2){
			ans++;
		}
		//cout<<sum<<" "<<mx<<" "<<ans;
		//cout<<endl;
		
	} 
	for(int i=m;i<=n;i++){
		if(vis[i]==0&&s[m-1]<=a[i]){
			vis[i]=1;
			s[m]=a[i];
			dfs(m+1); 
			vis[i]=0;
		} 
	}
	return;
}
int main(){
freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans%mod;
	return 0;
}
//DFS---40%
//dp---100%