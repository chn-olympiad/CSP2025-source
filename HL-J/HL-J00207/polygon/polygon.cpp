#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[5050],truth[5050],ans,n;

bool check(int k){
	if(k<3) return false;
	int maxn=-1,sum=0;
	for(int i=1;i<=k;i++){
		sum+=a[truth[i]];maxn=max(maxn,a[truth[i]]);
		
	}
	

	return sum>(2*maxn);
}


void dfs(int k,int l){
	if(check(k)) ans=(ans+1)%Mod;
	for(int i=l;i<=n;i++){
		truth[++k]=i;
		dfs(k,i+1);
		truth[k--]=0;
	}
}



int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,1);
	cout<<ans;
	return 0;
} 
