#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005],b[10005],x,y,z;
int maxx=1,maxx1=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)cin>>x>>y>>z,a[x]+=z,b[x]++,b[y]++;
	for(int i=1; i<=k; i++)
		for(int i=1; i<=n+1; i++)cin>>x;
	for(int i=1; i<=10000; i++)
		if(maxx<b[i])maxx=b[i],maxx1=i;
	cout<<a[maxx1];
	return 0;
} 
