#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int w[1000];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,l,r;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>w[i];
		a[l][r]=i;
		a[r][l]=i;
	}
	return 0;
}
