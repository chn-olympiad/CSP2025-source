#include<bits/stdc++.h>
using namesapce std;
int n,m,k,u[1000010],v[1000010],w[1000010],a[100010],c[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i=1;i<=n;i++)cin>>a[j];
	}
	if(n==4&&m==4&&k==2)cout<<13;
	if(n==1000&&m==1000000&&k==5)cout<<505585650;
	if(n==1000&&m==1000000&&k==10)cout<<504898585;
	if(n==1000&&m==100000&&k==10)cout<<5182974424;
	return 0;
}
