#include <bits/stdc++.h>
using namespace std;
int n,m,ans,vis[505],p[505],a[505],c[505];
string s;
void dfs(int k){
	if(k==n+1){
		int res=0,l=0;
		for(int i=1;i<=n;i++){
			if(res>=c[p[i]])res++;
			else{
				if(a[i]==1)l++;
				else res++;
			}
		}
		if(l>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; 
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=s[i-1]-'0';
	} 
	dfs(1);
	cout<<ans;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
