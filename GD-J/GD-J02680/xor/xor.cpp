#include<bits/stdc++.h>
using namespace std;
long long a[500001],n,k,ans;
void dfs(long long l,long long s){
	if(l>n) ans=max(ans,s);
	int s1=a[l];
	if(s1==k) dfs(l+1,s+1);
	for(int i=l;i<=n;i++){
		s1^=a[i];
		if(s1==k) dfs(i+1,s+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++)
		dfs(i,0);
	cout<<ans;
	return 0;
}
