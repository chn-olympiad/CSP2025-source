#include<iostream>
#include<algorithm>
using namespace std;
const int M=1000010;
int n,m,k,u,v,w[M];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++) cin >> u >> v >> w[i];
	sort(w+1,w+m+1);
	if(k==0){
		for(int i=1;i<=n-1;i++) ans+=w[i];
	}
	else ans=0;
	cout << ans;
	return 0;
}
