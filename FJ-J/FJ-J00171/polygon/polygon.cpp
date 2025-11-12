#include<bits/stdc++.h>
using namespace std;

int n,a[5005];
long long cnt;

void dfs(int ans,int k,int p){
	for(int i=k+1;i<=n;i++){
		if(p+1>=3&&ans>a[i]) cnt++,cnt%=998244353; 
		dfs(ans+a[i],i,p+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
