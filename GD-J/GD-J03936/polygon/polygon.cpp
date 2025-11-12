#include<bits/stdc++.h>
using namespace std;
int n,ans1;
int a[5005];
vector<int>e;
void dfs(int p){
	if(p==n+1){
		int sum=0,ans=-1;
		for(int i:e){
			sum+=i;
			ans=max(ans,i);
		}
		if(sum>ans*2){
			ans1++;
			ans1%=998244353;
		}
		return;
	}
	e.push_back(a[p]);
	dfs(p+1);
	e.pop_back();
	dfs(p+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans1-1;
	return 0;
} 
