#include<bits/stdc++.h>
using namespace std;

int n,a[5010],ans;

void dfs(int i,int c,int m,bool b){
	if(c>m*2 && b){
		ans=(ans+1)%998244353;
	}
	if(i>n) return;
	dfs(i+1,c,m,0);
	dfs(i+1,c+a[i],max(a[i],m),1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans/2;
	
	return 0;
}
