#include <bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0,a[10002],b[10002];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<10002;i++){
		a[i]=1e9;
		b[i]=0;
	}
	for(int i=0;i<m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u]=a[v]=1;
		b[i]=min(w,a[u+1]);
		a[u+1]=w;	
	}
	for(int i=0;i<10002;i++){
		if(b[i]!=0){
			ans+=b[i];
		}
	}
	cout<<ans;
	return 0;
}
