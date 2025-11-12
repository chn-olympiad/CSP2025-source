#include<bits/stdc++.h>
using namespace std;
const int p=998244353; 
int n;
int a[5010],c[5010],b[5050],ans; 
void dfs(int x){
	if(x>3){
		int sum=0,mx=-1;
		for(int i=1;i<x;i++){
			sum+=a[c[i]],mx=max(mx,a[c[i]]); 
		} 
		if(sum>2*mx){
			++ans; 
		} 
		ans%=p; 
	}
	if(x==n+1)
		return;  
	for(int i=max(1,c[x-1]);i<=n;i++){
		if(b[i]!=1){
			c[x]=i;
			b[i]=1;
			dfs(x+1);
			b[i]=0; 
		} 
	} 
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	int ok=1; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		if(a[i]!=1) ok=0; 
	} 
	if(ok){
		int ans=0; 
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
			ans%=p; 
		} 
		cout<<ans;
		return 0; 
	} 
	sort(a+1,a+n+1); 
	dfs(1); 
	cout<<ans; 
} 
