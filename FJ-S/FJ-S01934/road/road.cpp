#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	vector<int> g[N];
	int c[10][N];
	int a[N][N];
	int n,m,k;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();
		v=read();
		w=read();
		a[u][v]=w;
		a[w][u]=w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		int f,p;
		f=read();
		for(int j=1;j<=n;j++){
			p=read();
			c[i+1][j]=p;
		}
	}
	cout<<0;
	return 0;
}
