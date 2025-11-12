#include<bits/stdc++.h> 
using namespace std;
int n,k;
int ans=-1; 
int a[1000010];
int dfs(int len,int ch){
	len=(len^a[ch]);
	if(len==k){ 
		if(ch==n-1){
			return 1;
		}
		for(int i=ch+1;i<n;i++){
			return dfs(0,i)+1;
		} 
	}else{
		for(int i=ch+1;i<n;i++){
			return dfs(len,i);
		} 
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		ans=max(ans,dfs(0,k));
	} 
	cout<<ans; 
	return 0; 
}
