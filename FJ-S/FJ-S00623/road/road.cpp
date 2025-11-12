#include<bits/stdc++.h>
using namespace std;
int n,ans,a[2000001],d[1000001],m,k,bj[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
	}
	int mi=999999999;
	for(int i=1,x;i<=k;i++){
		cin>>x;bj[i]+=x;
		for(int j=1,z;j<=n;j++){
		cin>>z;bj[i]+=z;
		}
		mi=min(mi,bj[i]);
	}
	for(int i=1;i<=k;i++){
	if(bj[i]==0){cout<<"0";return 0;}
	}
	cout<<mi;
	return 0;
}