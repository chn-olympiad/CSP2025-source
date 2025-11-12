#include <bits/stdc++.h>
using namespace std;

int n,m,k,c;
long long mn = 1e18;
long long sum=0;
int a[10010];
struct node{
	int u,v,w;
}q[1000010];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		cin >> q[i].u >> q[i].v >> q[i].w;
	}
	while(k--){
		cin >> c;
		sum += c;
		for(int i = 1;i<=n;i++){
			cin >>a[i];
			sum += a[i];
		}
		mn = min(mn,sum);
	}
	cout << mn;
	
	
	return 0;
}
