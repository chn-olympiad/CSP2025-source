#include <bits/stdc++.h>
using namespace std;
int n,m,k;

struct C{
	int b,e,cost;
}c[1000005];

int c1[15],c2[15][10004],cs[15];
int r[15][10004],f[15],ans=1e9;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)f[i]=n;
	for(int i=1;i<=m;i++){
		cin>>c[i].b>>c[i].e>>c[i].cost;
	}
	for(int i=1;i<=k;i++){
		cin>>c1[i];
		for(int j=1;j<=n;j++){
			cin>>c2[i][j];
			cs[i]+=c2[i][j];
		}
		cs[i]+=c1[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			ans=min(ans,cs[i]);
			if(!r[i][c[j].b]){
				cs[i]-=c2[i][c[j].b];
				r[i][c[j].b]=1;
			}else f[i]--;
			if(!r[i][c[j].e]){
				cs[i]-=c2[i][c[j].e];
				r[i][c[j].e]=1;
			}else f[i]--;
			cs[i]+=c[i].cost;
			//cout<<i<<" "<<j<<" "<<cs[i]<<endl;
			if(!f[i]){
				cs[i]-=c1[i];
				break;
			}
			ans=min(ans,cs[i]);
		}
	}
	cout<<ans;
	return 0;
}
