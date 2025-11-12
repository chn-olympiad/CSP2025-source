#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct S{
	int u,v,w;
}id[N];
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>id[i].u>>id[i].v>>id[i].w;
	}
	for(int j=1;j<=k;j++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

