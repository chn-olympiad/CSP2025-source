#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,u[N],v[N],w[N],c[20],sum,minn=N,a=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
		if(u[i]!=0||v[i]!=0||w[i]!=0) a=0;
		sum+=w[i];
	}
	for(int i=1;i<=k;i++){
		minn=N;
		for(int j=1;j<=n+1;j++){
			cin >> c[i];
			if(c[i]!=0) a=0;
			if(i!=1&&i!=c[1]) minn=min(c[i],minn);
		}
		sum+=c[1];
		sum+=c[1+m];
		sum+=minn;
	}
	if(a==1) cout << 0;
	else cout << sum;
}
