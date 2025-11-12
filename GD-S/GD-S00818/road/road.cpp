#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int K=15;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N];
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
		cin>>c[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
		sum+=w[i];
	cout<<sum;
	return 0;
}
