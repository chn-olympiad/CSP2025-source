#include<bits/stdc++.h>
using namespace std;
struct un{
	int u,v,w;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int c[k],ans=0,a[k][n];
	un p[m];
	for(int i=0;i<m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
		p[i].u--;
		p[i].v--;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int j=0;j<k;j++){
		int t=0;
		for(int i=0;i<m;i++){
			if(p[i].w>a[j][p[i].u]+a[j][p[i].v]) 
				t=p[i].w-a[j][p[i].u]-a[j][p[i].v];
		}
		t-=c[j];
		if(t>0) ans-=t;
	}
	for(int i=0;i<m;i++){
		ans+=p[i].w;
	}
	cout<<ans;
	return 0;
}
