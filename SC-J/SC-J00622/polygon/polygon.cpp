#include<bits/stdc++.h>
using namespace std;
long long a[10010];
long long n,ans=0;
void dfs(long long m,long long p,long long pp,long long o,long long k){ 
	if(k>m){
		if(2*p<o)ans++;
		return;
	}for(long long i=pp;i<n;i++){
		dfs(m,a[i],i+1,o+a[i],k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=3;i<=n;i++)
	dfs(i,0,0,0,1);
	cout<<ans;
	return 0;
}