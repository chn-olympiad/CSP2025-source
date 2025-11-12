#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500001];
void dfs(int sum,int p){
	if(p>n){
		//ans++;
		//cout<<ans<<endl;
		return ;
	}
	for(int i=p;i<=n;i++){
		dfs(sum+a[i],i+1);
		if(a[i]<sum){
			ans++;
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
	sort(a+1,a+n+1);           
	dfs(0,1);
	cout<<ans;
	return 0;
}
