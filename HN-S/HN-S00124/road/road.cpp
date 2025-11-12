#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long c[15],a[15],ans;
struct node1{
	long long u;
	long long v;
	long long w;
};
node1 city[1000005];
struct node2{
	long long c;
	long long a[10005];
};
node2 contryside[15]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>city[i].u>>city[i].v>>city[i].w;
		ans+=city[i].u+city[i].v+city[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>contryside[i].c;
		ans+=contryside[i].c;
		for(long long j=1;j<=n;j++){
			cin>>contryside[i].a[j];
			ans+=contryside[i].a[j];
		}
	}
	cout<<ans/10086;
	return 0;
}
