#include<bits/stdc++.h>
using namespace std;
const int N=505;
int u[N],v[N],w[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]>v[i])swap(u[i],v[i]);
		sum+=w[i];
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int a;cin>>a;
		}
	}
	cout<<sum;
	return 0;
}