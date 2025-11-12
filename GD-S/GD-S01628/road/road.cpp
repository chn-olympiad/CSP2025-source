#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;
int n,m,k,u,v,w,d[100005][100005];
int a1,c[10005],ans;
int s,a;
bool p[10005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
	}
	for(int i=1;i<=k;i++) {
		cin>>s;
		a1=max(a1,s);
		for(int j=1;j<=n;j++) {
			cin>>a;
			d[i][j]=a;
		}
	}
	for(int i=1;i<=n;i++) c[i]=d[n][i];
	for(int i=1;i<n;i++) {
		int k=0;
		for(int j=1;j<=n;j++) {
			if(!p[j]&&c[j]>c[k])	k=j;
		}
		p[k]=true;
		ans+=c[k];
		for(int j=1;j<=n;j++) {
			if(!p[k]&&d[i][j]<d[k][j]+c[k]) d[i][j]=d[k][j]+c[k];
		} 
	}
	cout<<ans+a1;
	return 0;
}
