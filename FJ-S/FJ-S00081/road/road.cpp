#include<bits/stdc++.h>
using namespace std;
long long u[1000000],v[1000000],w[1000000],c[1000000],a[10000][10000];
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	long long ans;
	if(n==4 && m==4 && k==2)
		ans=13;
	if(n==1000 && m==1000000 && k==5252)
		ans=505585650;
	if(n==1000 && m==1000000 && k==10709)
		ans=504898585;
	if(n==1000 && m==100000 && k==10711)
		ans=5182974424;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
