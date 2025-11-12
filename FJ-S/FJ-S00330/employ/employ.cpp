#include <bits/stdc++.h>
using namespace std;
int n,m,c[105],ans,k[105];
string q;
void dfs(int s,int a[],int p,int x){
	if(x==n){
		if(p>=m) ans++;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=1;
			if(s<=c[i]&&q[i-1]==1) p++;
			else s++;
			dfs(s,a,p,x+1);
			a[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++) cin>>c[i];
	dfs(0,k,0,0);
	cout<<ans;
	return 0;
}
