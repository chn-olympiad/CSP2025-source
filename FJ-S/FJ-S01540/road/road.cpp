#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[100005],v[100005],w[100005],c[1000015];
long long a[1000015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i]; 
	for(int i=1;i<=k+m;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	int sum=u[1]+v[1]+w[1]+c[1]+a[1];
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
