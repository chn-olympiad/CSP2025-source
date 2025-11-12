#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum=0;
void dfs(int p,int total,int s,int maxx){
	if(s>=3&&total-maxx>maxx){
		sum++;
	}
	if(p>=n)return;
	dfs(p+1,total,s,maxx);
	dfs(p+1,total+a[p+1],s+1,max(maxx,a[p+1]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],1,a[i]);
	}
	sum-=2;
	cout<<sum%998244353;
}
