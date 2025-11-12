#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cs=0;
	cin>>n>>m>>k;
	int u[1000010],v[1000010],w[1000010],c[1000010],a[1000010];
	for(int i=0;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]<v[i]&&u[i]<w[i]){
			cs=cs+u[i];
		}else if(v[i]<u[i]&&v[i]<w[i]){
			cs=cs+v[i];
		}else{
			cs=cs+w[i];
		}
	}
	for(int j=1;j<=k;j++){
		cin>>c[j]>>a[n];
		if(a[j]<c[j]){
			cs=cs+a[j];
		}else{
			cs=cs+c[j];
		}
	}
	cout<<cs;
	return 0;
}
