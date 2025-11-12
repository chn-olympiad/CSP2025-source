#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100040],x[10040],y[100040],z[100040],b,c,d,e,f,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin >>x[i]>>y[i]>>z[i];
	}
	for (int i=1;i<=k;i++){
		cin >>b>>c>>d>>e>>f;
	}
	for(int i=1;i<=n;i++){
		ans+=z[i];
	}
	cout <<ans;
	return 0;
}
