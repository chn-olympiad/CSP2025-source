#include<bits/stdc++.h>
using namespace std;
#define N 500005

int n,k,anss;
int a[N],zz[N],an[N];

void dfs(int id,int sum,int ans,int vis){
	if(id>n){
		anss=max(anss,ans);
		return ;
	}
	for(int i=id;i<=n;i++){
		if((sum^a[i])==k){
//			cout<<sum<<" "<<a[i]<<" "<<(sum^a[i])<<" "<<k<<endl;
			dfs(i+1,0,ans+1,0);
		}
		else{
			dfs(i+1,sum^a[i],ans,1);
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<anss;
	return 0;
}
/*
4 0 
2 1 0 3 

10 1
1 0 1 0 1 0 1 1 1 0

100 1 
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/