#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int s[500005];
void dfs(int now,int ss){
	ans=max(ans,ss);
	for(int i=now;i<=n;i++){
		for(int j=now;j<=i;j++){
			if((s[i]^s[j-1])==k){
				dfs(i+1,ss+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
