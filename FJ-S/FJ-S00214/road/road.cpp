#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+3;
int n,m,k,u[N],v[N],w[N],ans;
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=0;i<m;i++)cin >>u[i]>>v[i]>>w[i],ans+=w[i];
	cout <<ans;
	return 0;
}
