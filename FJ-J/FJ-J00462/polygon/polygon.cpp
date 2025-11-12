#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],jl[1000001],cnt=0,sum=0;
const long long mod=998244353;
void dfs(int sl,int zs,int id,int ans,int zd){
	if(sl==zs&&ans>zd*2){
	sum++;
	sum%=mod;
	return;
}
for(int i=id;i<=n;i++){
	if(a[i]<=zd)dfs(sl+1,zs,i+1,ans+a[i],zd);
	else dfs(sl+1,zs,i+1,ans+a[i],a[i]);
}
}
int main() {
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
	dfs(0,i,1,0,0);
}
cout<<sum;
	return 0;
}/*
5
1 2 3 4 5

5
2 2 3 8 10

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

10
0 1 1 0 0 1 1 1 1 
*/