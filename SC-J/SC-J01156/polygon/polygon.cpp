#include<bits/stdc++.h>
using namespace std;
int n,k;
int t,e,ji=0;
int b,c;
int a[10005];
void dfs(int x,int he,int maxx){
	if(x==n+1){
		return;
	}
	if(he+a[x]>maxx*2){
		ji++;
		dfs(x+1,he,maxx);
		dfs(x+1,he+a[x],max(maxx,a[x]));
	}else{
		dfs(x+1,he,maxx);
		dfs(x+1,he+a[x],max(maxx,a[x]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=-1;
	if(n<=3){
		cin>>e>>b>>c;
		int maxx=max(e,max(b,c));
		if(e+b+c>maxx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	} else{
		int g=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				g++;
			}
		}
		if(g==n){
			cout<<(n-1)*(n-2)/2;
			return 0;
		}
		for(int i=1;i<=n;i++){
			dfs(i,0,-1);
		}
		cout<<ji;
	}        
	return 0;
}