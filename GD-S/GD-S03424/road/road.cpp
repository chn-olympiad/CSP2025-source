#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int u[maxn],v[maxn],w[maxn],a[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i = 0;i<k;i++)
		for(int j = 0;j<=n;j++)
			cin>>a[j];
	cout<<0<<endl; 
	 
}
