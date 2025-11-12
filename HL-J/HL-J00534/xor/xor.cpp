#include<bits/stdc++.h>
using namespace std;

int n,k,a[500000];
int m;

void dfs(int l,int r){
	if(l==n&&r==n){
		
	}
	int t=a[l];
	for(int i=l+1,i<=r,i++){
		t=t^a[i];
	}
	if(t!=k){
		if(r==n){
			
		}else{
			dfs(l,r+1);
		}
	}else{
		
	}
	
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<m;
	
	return 0;
}
