#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin >> n >> m >> k;
	long long a[100005][100005],u[100005]={},v[100005]={},w[100005]={},wgjy[100005]={},wgjy2[100005]={};
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
		a[u[i]][v[i]]=w[i];
	} 
	for(int i=1;i<=k;i++){
		cin >> wgjy[i];
		for(int i=1;i<=n;i++){
			cin >> wgjy2[i];
		} 
	}
	for(int i=1;i<=m;i++){
		sum+=max(a[u[i]][v[i]],a[v[i]][u[i]]);
	}
	cout << sum;
	return 0;
} 
