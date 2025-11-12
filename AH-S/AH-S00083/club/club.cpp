#include <bits/stdc++.h>
using namespace std;
int num1[100001],num2[100001],num3[100001],t,n,ans;
void dfs(int dep,int x,int y,int z,int cur){
	if(dep==n+1){
		ans=max(ans,cur);
		return ;
	}
	if(x>0){
		dfs(dep+1,x-1,y,z,cur+num1[dep]);
	}
	if(y>0){
		dfs(dep+1,x,y-1,z,cur+num2[dep]);
	}
	if(z>0){
		dfs(dep+1,x,y,z-1,cur+num3[dep]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>num1[i]>>num2[i]>>num3[i];
		}
		if(n<=20)dfs(1,n/2,n/2,n/2,0);
		else {
			if(num3[1]==0&&num2[1]==0){
				sort(num1+1,num1+1+n);
				for(int i=n;i>=n/2;i++){
					ans+=num1[i];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
