#include<bits/stdc++.h>
using namespace std;

int n,m,k,u[10005],v[10005],w[10005],c,a[1000005],s;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>u[i]>>v[i]>>w[i];
	cin>>c;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	cout<<s;
	return 0;
}
