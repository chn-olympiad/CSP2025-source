#include<bits/stdc++.h>
using namespace std;
int n,ans,arr[5005],f;
void dfs(int a,int b,int c,int d){
	if(a>=3 && f==0){
		ans++;
		ans=ans%998244353;
	}
	f=0;
	for(int i=b+1;i<=n;i++){
		int y=max(arr[i],d);
		if(a<2 || 2*y<c+arr[i]){
			dfs(a+1,i,c+arr[i],y);
		}
		f=1;
		dfs(a,b+1,c,d);
		f=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
