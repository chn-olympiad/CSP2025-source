#include<bits/stdc++.h>
using namespace std;
int a[1145140],r,n,k,ans;
void dfs(int step,int key,int maxn,int bs,bool flag){
	if(step>n+1||n+1-step+bs<3)return;
	if(bs>=3&&!flag){
		if(key>2*maxn){
			ans++;
		}
	}
	dfs(step+1,key+a[step],a[step],bs+1,0);
	dfs(step+1,key,maxn,bs,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
