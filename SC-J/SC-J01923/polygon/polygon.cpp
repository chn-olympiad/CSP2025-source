#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s;
map<int,map<int,map<int,bool> > >f;
void dfs(int k,int g,int c,int m){
	if(k>n+1)return;
	if(c>2*m&&g>=3){
		if(!f[g][c][m]){
			f[g][c][m]=1;
			s++;
			s%=998244353;
		}
	}
	dfs(k+1,g,c,m);
	dfs(k+1,g+1,c+=a[k],max(m,a[k]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])s++;
	}
	dfs(1,0,0,0);
	cout<<s;
	return 0;
}