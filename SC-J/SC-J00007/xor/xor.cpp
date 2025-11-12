#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,k,maxx=0,ans=0;
void dfs(int l,int r,int s){
	if(l>n||r>n)
		return ;
	if((s^a[r])==k){
		ans++;
		dfs(r+1,r+1,0);
	}
	else{
		dfs(l,r+1,s^a[r]);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=0;
		dfs(i,i,0);
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}