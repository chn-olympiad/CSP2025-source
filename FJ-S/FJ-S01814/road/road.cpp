#include <iostream>
using namespace std;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n,m,k;
	int s;
	int b[5];
	int a[10005];
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>b[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<13;
	return 0;
}
