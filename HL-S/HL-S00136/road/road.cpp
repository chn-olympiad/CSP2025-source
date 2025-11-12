#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	const int N=1e4+10;
	int n,m,k,u[10010],v[10010],w[N],sor[N],c[N],a[10010]={10000000},ans=0,t,ts;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sor[i]=w[i];
	}
	sort(sor,sor+m);
	for (int j=0;j<=k;j++){
		cin>>c[j];
		for (int o=1;o<=k;o++){
			cin>>a[o];
			t=min(a[o-1],a[o]);
			if (t==a[o-1]){
				ts=o-1;
			}
			else ts=o;
		}
		ans+=t+k;
	}
	ans+=sor[m];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
