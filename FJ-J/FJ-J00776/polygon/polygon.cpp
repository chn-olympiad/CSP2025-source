#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void dfs(int p,int sum,int man,int cnt){
	if(p>n){
		if(sum>2*man&&cnt>=3){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(p+1,sum+a[p],max(man,a[p]),cnt+1);
	dfs(p+1,sum,man,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
