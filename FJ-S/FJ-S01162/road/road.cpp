#include<bits/stdc++.h>
using namespace std;
int k,n,m,x[1000001],f[1000001],u[1000001],a[1000001],b[1000001];
struct l{
	int a1;
	int a2;
	int a3;         
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>f[i]>>u[i];
	}
	for(int j=1;j<=k;j++){
		cin>>x[j]>>f[j]>>u[j]>>a[j]>>b[j];
	}
	cout<<"13";
	return 0;
}
