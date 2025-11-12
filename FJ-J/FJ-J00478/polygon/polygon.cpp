#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,ans,a,b,c,s,g;
struct node{
	int u,v,w;
}e[10001];
void dfs(int x){
	if(x>n) return;
	for(int i=x+1;i<=n;i++){
		b=max(e[x].u,e[i].v);
		c=e[x].w+e[i].v;
		if(b>2*c) s++;
		dfs(e[i].v);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		cin>>a>>b>>c;
		g=max(max(a,b),c);
		s=a+b+c;
		if(s>g*2) cout<<1;
		else cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cout<<e[i].v;
	}
	s=1;
	n=n-3;
	while(n){
		s=n*s;
		n--;
	}
	cout<<s;
	dfs(2);
	return 0;
}
