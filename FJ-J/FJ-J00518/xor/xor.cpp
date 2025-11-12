#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
void dfs(int x,int i){
	if(x==k){
		ans++;
		return;
	}else if(i+1<n&&a[i+1]!=k) dfs((x^a[i+1]),i+1);	
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) dfs(a[i],i);
	cout<<ans;
	return 0;
}
