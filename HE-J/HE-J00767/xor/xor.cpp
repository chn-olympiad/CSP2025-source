#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],ans;
void dfs(){
	if(sum==k){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		dfs(); 
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs();
	cout<<ans;
	return 0;
}
