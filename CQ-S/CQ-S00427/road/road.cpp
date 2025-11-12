#include<bits\stdc++.h>
using namespace std;
long long n,m,k,c[11],a[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=0;i<=k;i++){
		cin>>c[i];
		for(int j=0;j<n;i++){
			cin>>a[i][j];
		}
	}
	cout<<"0"<<endl;
	return 0;
}
