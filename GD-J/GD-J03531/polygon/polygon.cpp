#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,g,b[5005],l;
void dfs(int t,int s,int m){
	if(t>n){
		if(s>2*m&&g>=3){
			ans++;
		}
		return;
	}
	dfs(t+1,s,m);
	g++;
	dfs(t+1,s+a[t],max(m,a[t]));
	g--;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
