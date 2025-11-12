#include<bits/stdc++.h>
using namespace std;
int n,k,ns[500005],ans;
void dfs(int endx,int cs){
	ans=max(ans,cs);
	if(endx+1>n){
		return;
	}
	int rc=ns[endx+1];
	for(int i=endx+1;i<n;i++){
		//cout<<"ex:"<<endx<<" cs:"<<cs<<" i:"<<i<<" rc:"<<rc<<endl;
		if(i>endx+1){
			rc=rc^ns[i];
		}
		if(rc==k){
			dfs(i,cs+1);
		}
		
	}
	dfs(endx+1,cs);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>ns[i];
	}
	dfs(-1,0);
	cout<<ans; 
	return 0;
}
