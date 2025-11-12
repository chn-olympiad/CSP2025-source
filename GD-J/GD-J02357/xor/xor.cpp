#include<iostream>
using namespace std;
int n;
unsigned int k,pre[500010],a,cnt,ans,res;
void dfs(int l){
	for(int i=l,flag=0;i<=n;i++){
		if((pre[i]^pre[l-1])==k) res++,flag=1;
		dfs(i+1);
		res-=flag;
		flag=0;
	}
	ans=max(ans,res);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		pre[i]=pre[i-1]^a;
	}
	dfs(1);
	cout<<ans;
}
