#include<bits/stdc++.h>
using namespace std;
int n,m,c[511];
string s;
int p[511];
long long sm;
int dfs(int nx,int bl,int fqrs,int m){
	for(int i=1;i<=n;i++){
		if(nx<=fqrs||s[bl]==0){
			fqrs++;
		}
		if(p[i]!=1){
			bl++;
			if(dfs(c[bl],bl,fqrs,m)>=m){
				sm++;
			}
		}
	}
	return sm;
}
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<dfs(c[1],1,0,m);
	return 0;
} 
