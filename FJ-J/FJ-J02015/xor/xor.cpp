#include<bits/stdc++.h >
using namespace std;	
int n,k,h=1;	
int a[50010]={};	
int p[50010]={};
void dfs(int b){
	p[b]=p[b-1]^a[b];
	if(p[b]==k){
		h++;
		p[b]=0;
		return dfs(b++);
	}
	if(b==n)	return;
	return dfs(b++);
}
int main(){
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i);
		ans=max(ans,h);
		h=1;
	}
	cout<<ans;
	return 0;
}
