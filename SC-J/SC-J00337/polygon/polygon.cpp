#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int cnt;
int a[5005],ans=0,n;
int t[5005][5005]; 
void dfs(int k,int sum,int mx,int pos){
	if(k==cnt+1){
		if(mx*2<sum) ans++;
		ans%=mod;
		return;
	}
	for(int i=pos+1;i<=n;i++){
		dfs(k+1,sum+a[i],max(mx,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(cnt=3;cnt<=n;cnt++){
			dfs(1,0,0,0);
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=n;i++) t[0][i]=1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			t[i][j]=t[i][j-1]+t[i-1][j-1];
			t[i][j]%=mod;
		}
	}
	for(int i=3;i<=n;i++){
		ans+=t[i][n];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}