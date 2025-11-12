#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],maxt;
void dfs(int s,int x,int y,int z){
	if(y==n+1){
		maxt=max(maxt,s);
		return;
	}
	dfs(s,x,y+1,z xor a[y+1]);
	if(z==k)s++;
	dfs(s,y+1,y+1,a[y+1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,1,a[1]);
	cout<<maxt;
	return 0;
}
