#include <iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int count=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		count+=w;
	}
	for(int j=1;j<=k;j++){
		int money;
		for(int q=1;q<=n;q++){
			int x;
			cin>>x;
			count+=x;
		}
		cin>>money;
		count+=money;
	}
	cout<<count;
    return 0;
}
