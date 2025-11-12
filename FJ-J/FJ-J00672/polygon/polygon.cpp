#include<bits/stdc++.h>
using namespace std;
int ans,n;
int a[5001];
void dfs(int x,int y,int z){
	if(y>=n){
		return;
	}
	if(z>=2&&x>a[y]){
		ans++;
	}
	dfs(x+a[y],y+1,z+1);	
	dfs(x,y+1,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0,0); 
	cout<<ans%998244353;
	return 0;
} 
