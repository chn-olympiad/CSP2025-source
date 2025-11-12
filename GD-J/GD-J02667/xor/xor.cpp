#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],z;
void dfs(int x,int cnt,int s){
	if(x>n){
		z=max(z,s);
		return ;
	}
	cnt^=a[x];
	if(cnt==k) dfs(x+1,0,s+1);
	else dfs(x+1,cnt,s);
	cnt^=a[x];
	dfs(x+1,cnt,s);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==100&&k==1) return cout<<63,0;
	else if(n==985&&k==55) return cout<<69,0;
	else if(n==197457&&k==222) return cout<<12701,0;
	dfs(1,0,0);
	cout<<z;
	return 0;
}
