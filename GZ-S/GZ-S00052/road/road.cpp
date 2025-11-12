//GZ-00052 华东师范大学附属贵阳学校 刘宇宸 
#include <bits/stdc++.h>
using namespace std;
int n,m,k,fe;
long long x,v[1000050],w[1000050],u[1000050],c[100050],a[15][100050],mi[100050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
			mi[j] = min(mi[j],a[i][j]);
			if(i==1){
				mi[j] = a[i][j];
			}
		}
	}
	for(int i = 1;i <= m;i++){
		x += min(mi[u[i]] + mi[v[i]],w[i]);
	}
	cout<<x;
	
	return 0;
}
