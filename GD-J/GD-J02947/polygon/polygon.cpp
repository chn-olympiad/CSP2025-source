#include<iostream>
using namespace std;
int len[5010];
int n,ans=0;
void dfs(int l,int step,int Max,int sum){
	if(l>n||step>n){
		return;
	}
	if(step>=3){
		if(sum>2*Max){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=l+1;i<=n;i++){
		
		dfs(i,step+1,max(Max,len[i]),sum+len[i]);
	}
	return; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
	}
	for(int i=1;i<=n-2;i++){
			dfs(i,1,len[i],len[i]);
	}
	cout<<ans;
	return 0;
}
