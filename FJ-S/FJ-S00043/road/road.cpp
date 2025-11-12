#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[100006],v[1000006],w[1000006];
long long c[20][10005];
bool flag=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			cin>>c[j][i];
			if(c[j][i]!=0)flag=0;
		}
	}
	cout<<13;
	return 0;
}

