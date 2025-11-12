#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int b[N],ans,n,k; 
void dfs(int now,int num){
	if(now==n+1){
		ans=max(ans,num);
		return;
	}
	for(int i=now;i<=n;i++){
		if((b[i]^b[now-1])==k)
			dfs(i+1,num+1);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=1)
		f=false;
		b[i]=b[i-1]^a;
	}
	if(f&&k==0){
		cout<<n/2;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}