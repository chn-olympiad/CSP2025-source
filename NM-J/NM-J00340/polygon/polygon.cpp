#include<bits/stdc++.h>
using namespace std;
int num[5005]={},n,fn=0;
void dfs(int dep,int mxl,int sum){
	if(dep==n){
		if(mxl*2<sum){
			fn++;
			fn=fn%998244353;
		}
		return ;
	}
	dfs(dep+1,max(mxl,num[dep]),sum+num[dep]);
	dfs(dep+1,mxl,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i];
	
	dfs(0,0,0);
	cout<<fn;
	return 0;
}
