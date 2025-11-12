#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0;
const int N=1e6+5,M=1e4+5;
struct mmp{
	int thx,thy,thz;
}a[N];
int b[15][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].thx,&a[i].thy,&a[i].thz);
		sum+=a[i].thz;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i][1]);
		for(int j=2;j<=n+1;j++){
			scanf("%d",&b[i][j]);
		}
	}
	cout<<sum;
	return 0;
}
