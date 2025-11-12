#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int a[5005];
bool check(int mx,int sm,int g){
	if(g<3)return 0;
	return sm>2*mx;
}

void dfs(int p,int mx,int sm,int g){
	if(p>=n){
		if(check(mx,sm,g))ans++;
		ans%=998244353;
		return;
	}
	dfs(p+1,max(mx,a[p]),sm+a[p],g+1);
	dfs(p+1,mx,sm,g);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
