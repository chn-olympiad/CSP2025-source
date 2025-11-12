#include<bits/stdc++.h>
using namespace std;
int arr[5100],ans=0;int n,lmaxx=0;
void dfs(int x,int maxx,int sum){
	if(2*maxx<sum){
		ans++;
		ans%=998244353;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,max(maxx,arr[i]),sum+arr[i]);
	}	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		lmaxx=max(lmaxx,arr[i]);
	}

	dfs(0,0,0);
	cout<<ans%998244353;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
