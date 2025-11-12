#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5005;
int a[N];
int n;
const int mod=998244353;

int dfs(int k,int v,int sum,int mx){
	if(k==n&&sum>2*mx&&v>=3) return 1;
	if(k<n) return dfs(k+1,v,sum,mx)%mod+dfs(k+1,v+1,sum+a[k+1],max(mx,a[k+1]))%mod;
	return 0;
}

int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=false;
	}
	if(f==true) cout<<0;
	else cout<<dfs(0,0,0,0)%mod;
	
	return 0;
}
