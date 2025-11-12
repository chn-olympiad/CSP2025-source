#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int u,v, w;
}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
