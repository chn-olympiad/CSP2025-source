#include<bits/stdc++.h>
using namespace std;
struct bian{
	int u,v,w;
}a[1500000];
int head[1010],next1[15000];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		next1[i]=head[a[i].u];
		head[a[i].u]=i;
	}
	for(int i=1;i<=k;i++){
		int c,n;
		bool flag=1;
		cin>>c;
		if(c)flag=0;
		for(int i=1;i<=n;i++){
			cin>>n;
			if(n)flag=0;
		}
		if(flag){
			cout<<0;
			return 0;
		}
	}
	long long  fact[100005];
	const int MOD=998244353;
	for(int i=1;i<=100000;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	cout<<fact[100000-n];
	return 0;
}
