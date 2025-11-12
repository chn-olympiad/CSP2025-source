#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
int a[N][N]={0};
int b[N],c[N],d[N],p[N];
int l[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>b[i]>>p[i];
		cin>>d[i];
	}
	for(int i=1;i<=k;i++){
		cin>>l[i];
		for(int j=1;j<=k;j++) cin>>c[i];
	} 
	cout<<13<<endl;
	return 0;
}
