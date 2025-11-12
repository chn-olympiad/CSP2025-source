#include <bits/stdc++.h>
using namespace std;

int n,m,k,j,q=0,R;
int u[100005],v[100005],w[100005];
int c[10],a[10][100005]{0},
	Ro[10000005]{0};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int p=0;
	cin>>n>>m>>k;R=n+k-1;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];q++;
	}
	for(;p<k;){
		p++;cin>>c[p];
		for(int i=1;i<=n;i++){
			cin>>a[p][i];
		}	
	}
	
	for(int y=0;y<(k+n+5);y++){
		if(q<n)Ro[y]=w[y];else
		for(int i=1;i<=n;i++){
			Ro[y+i]=a[y][i];
		}
	}
	sort(Ro,Ro+p+q);
	
	for(int i=1;i<R;i++){
		cout<<Ro[i];
	}
	return 0;
}
