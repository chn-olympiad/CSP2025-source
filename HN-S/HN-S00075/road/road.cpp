#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000006],v[1000006],w[1000006],c[11][1000006],q,sum,maxn;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
	    sum+=w[i];
	    q=max(w[i],q);
	}
	if(k==0){
    	cout<<sum-q;
    	return 0;
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[k][i];
		}
	}
	if(c[k][2]==0){
		maxn=sum-q;
		for(int i=1;i<=k;i++){
			maxn=min(maxn,c[k][1]);
		}
	}
	cout<<maxn;
	return 0;
}
