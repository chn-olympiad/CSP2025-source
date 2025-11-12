#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010],b[100010],c[100010],half,maxx=-1;
void dfs(long long xb,long long a1,long long b1,long long c1,long long he){
	if(xb==n+1){
		maxx=max(maxx,he);
		return;
	}
	if(a1-1!=-1)dfs(xb+1,a1-1,b1,c1,he+a[xb]);
	if(b1-1!=-1)dfs(xb+1,a1,b1-1,c1,he+b[xb]);
	if(c1-1!=-1)dfs(xb+1,a1,b1,c1-1,he+c[xb]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxx=-1;
		cin>>n;
		half=n/2;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		dfs(1,half,half,half,0);
		cout<<maxx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
