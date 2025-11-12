#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,b[N],ans=0;
struct{
	int u,v,w;
}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;ans+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i];ans+=b[i];
		}
	}
	cout<<ans;
	return 0;
}
