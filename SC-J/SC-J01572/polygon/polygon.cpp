#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;i++)
int a[5005],n,ans;
void dfs(int sum,int maxn,int id){
	if(sum>2*maxn) ans++;
	fo(i,id+1,n) dfs(sum+a[i],max(maxn,a[i]),i);
	return ;
}
bool AK=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	fo(i,1,n){
		cin>>a[i];
		if(a[i]!=1) AK=0;
	}
	if(AK){
		long long ans=n*(n-1)*(n-2)/6;
		cout<<ans;
		return 0; 
	}
	fo(i,1,n) dfs(a[i],a[i],i);
	cout<<ans;
	return 0;
}