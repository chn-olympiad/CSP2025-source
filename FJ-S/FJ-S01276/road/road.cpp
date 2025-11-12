#include<bits/stdc++.h>
using namespace std;
int a[1000005],c[1000005],d[1000005];
int b[1000][100005];
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	int n,m,k,h=0;
	cin>>n>>m>>k;
	int i=m;
	for(int x=1;x<=i;x++){
			cin>>a[x]>>c[x]>>d[x];
	}
	for(int x=0;x<k;x++){
		for(int y=0;y<=n;y++){
			cin>>b[x][y];
		}
	}
	for(int x=1;x<=i;x++){
		int f=b[x-1][a[x]]+b[x-1][c[x]]+b[x-1][x];
		if(d[x]<f){
			h+=d[x];
		}else{
			h+=f;
		}
	}
	cout<<h;
	return 0;
}
