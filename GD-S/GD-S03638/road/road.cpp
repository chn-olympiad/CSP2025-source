#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
LL n,m,k;
struct city{
	LL u,v,w;
}a[N];
struct node{
	LL c,t[N];
}b[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++){
			cin>>b[i].t[j];
		}
	}
	return 0;
}

