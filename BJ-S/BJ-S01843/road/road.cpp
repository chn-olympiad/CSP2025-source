#include <iostream>

using namespace std;

const int N=1e4+10;
const int M=1e6+10;

int n,m,k,a[11][N],ans=1e9+10,c[11];

struct node{
	int from,to,val;
}r[M];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		cin>>r[i].from>>r[i].to>>r[i].val;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
		ans=min(sum+c[i],ans);
	}
	cout<<ans;;
	return 0;
}
