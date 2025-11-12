#include <iostream>
using namespace std;
long long sum=0;
int u[1000005],v[1000005],w[1000005];
int c[1000005],a[100][1005];
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin >>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for (int i=1;i<=k;i++){
		cin >>c[i];
		for (int j=1;j<=n;j++)
			cin >>a[i][j];
	}
	if (k==0) {
		cout <<sum<<endl;
		return 0;
	}
	return 0;
}
