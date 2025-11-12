#include<bits/stdc++.h>
using namespace std;
int n;
int num[5005];
int ans=0;
void dfs(int idx,int tot){
	if(idx>n){
		if(tot>num[1]*2)ans++;
		return;
	}
	dfs(idx+1,tot+num[idx]);
	dfs(idx+1,tot);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long total=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		total+=num[i];
	}
	sort(num+1,num+n+1,greater<int>());
	dfs(1,0);
	cout<<ans+2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
