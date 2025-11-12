#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int e[2*N],ne[2*N],h[2*N],idx,w[N];
int n,m,k;
int a[15][N],c[15],value[N];
int u,v,we;
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(value,0x3f,sizeof value);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>we;
		add(u,v,we);
		add(v,u,we);

	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	value[0]=0;
	for(int i=h[0];i!=-1;i=ne[i]){
		int t=e[i];
		for(int j=1;j<=k;j++){
			value[t]=value[t-1]+w[i];
			if(value[t]>value[t-1]+a[j][t-1]+a[j][t]+c[j]){
				value[t]=value[t-1]+a[j][t-1]+a[j][t]+c[j];
			}
		}
	}
	cout<<value[n];
	return 0;
}
