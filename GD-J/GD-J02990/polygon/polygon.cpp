#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,a[5001]={};
void dfs(int x,int y,int sum,int maxn,int en){
	if(x>y){
		if(sum>2*maxn){
			ans++;
		}
		return;
	}
	for(int i=en+1;i<=n-y+x;i++){
		dfs(x+1,y,sum+a[i],a[i],i);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,i,0,a[1],0);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
