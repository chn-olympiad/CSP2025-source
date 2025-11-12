#include<bits/stdc++.h>
using namespace std;
int n,m,k;
unsigned long long sum,a[100005],b[1000005],x[100005],y[100005],c[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;i++){
			cin>>b[i];
		}
	}
	for(int i=1;i<=m;i++){
		 sum+=a[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
