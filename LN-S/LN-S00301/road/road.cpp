#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct nn{
	int u,v,w;
}a[1090101]
int c[11],qw[1001];
bool cmp(mn a,nn b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>qw[1];
		for(j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}

	sort(a+1,a+1+n,cmp);
	int sum=0;
	cout<<sum<<endl;
	return 0;
	
}
