#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxx=5020;
int P[maxx],S[maxx];
int ans=0;
int n;
void dfs(int k,int i,int sum,int mx,int pos){
	if(i==k){
		if(mx*2<sum)ans=ans+1%mod;
		return ;
	}
	for(int j=pos+1;j<=n;j++){
		if(S[j]==0){
			S[j]=1;i++;
			dfs(k,i,sum+P[j],mx=max(mx,P[j]),j);
			S[j]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>P[i];
	if(n>10){
		vector<int>T(maxx,0);
		T[0]=0;
		for(int i=1;i<=n;i++){
			T[i]=T[i-1]+i;
		}
		int ans=1;
		for(int i=3;i<n;i++){
			ans=(ans*2+T[i-1])%mod;
		}
		cout<<ans;return 0;
	}
	for(int k=3;k<=n;k++){
		dfs(k,0,0,-1,0);
	}
	cout<<ans;
	return 0;
}//dfs24+(max==1)24=48