#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],a[100050],t = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		t += w[i];
	}
	for (int i = 1;i <= k;i++){
		for (int j = 1;j <= n + 1;j++){
			scanf("%d",&a[j]);
		}
	}
	cout << t;
	return 0;
}
