#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sun,u[10001],v[10001],w[10001];
long long c[10001],a[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>a[j];
		sort(a+1,a+m+1);}
	sort(w+1,w+m+1);
	sort(c+1,c+k+1);
	for(int i=1;i<=k;i++)sun+=w[i];
	for(int i=1;i<=k/2;i++)sun+=c[i];
	for(int i=1;i<=m/2;i++)sun+=a[i];
	cout<<sun<<endl;
	return 0;
}