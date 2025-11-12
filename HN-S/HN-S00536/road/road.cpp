#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N][3];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		scanf("%d",&a[i][2]);
	}
	return 0;
}
