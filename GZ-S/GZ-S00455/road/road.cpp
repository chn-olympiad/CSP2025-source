//GZ-S00455 陈俊洁 周林学校
#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int n,m,k;
long long sum;
int u[N],v[N],w[N];
int a[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n+1; j++) {
			cin>>a[i];
			sum+=a[i+1];
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//我不会啊啊啊啊啊啊啊啊啊啊啊啊啊啊，乱写吧那就 
