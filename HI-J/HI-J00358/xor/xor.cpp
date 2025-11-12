#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],t=0;
bool f[100010];
int dfs(int x){
	if(x>n) return 0;
	int d=x,he=0,i;
	for(i=d;i<=n;i++){
		he=he^a[i];
		if(he==k) break;
	} 
	if(he==k) return 1+dfs(i+1);
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flagA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flagA=0;
	}
	if(flagA&&k==0){
		cout<<n/2;
		return 0;
	}
	for(int l=1;l<=n;l++){
		t=max(t,dfs(l));
	}
	cout<<t;
	
	
	
	
	
	return 0;
}
