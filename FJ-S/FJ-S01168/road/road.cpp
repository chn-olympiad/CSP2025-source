#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long u,v,w;
}a[1000005];
struct abc2{
	long long c,x[10005];
}b[20];
int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		for(long long i=1;i<=m;i++){
			ans+=a[i].w;
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=k;i++){
		cin>>b[i].c;
		for(long long j=1;j<=n;j++){
			cin>>b[i].x[j];
		}
	}
	return 0;
} 
