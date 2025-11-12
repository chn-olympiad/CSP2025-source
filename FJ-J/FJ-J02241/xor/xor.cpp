#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500005];
long long ans;

void dfs(long long x,long long last,long long sum){
	for(int i=x;i<=n;i++){
		last=last|a[i];		
		if(last==k)
			dfs(i+1,0,sum+1);
		dfs(i+1,0,sum);	
	}
	ans=max(ans,sum);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
