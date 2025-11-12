#include<bits/stdc++.h>
using namespace std;
int n,m,k,money=0;
int c[11],a[11][10001],u[1000001],v[1000001],w[1000001],f[10001][10001];
void cl(int b){
	for(int i=1;i<=n;i++){
		if(u[i]==b||v[i]==b){
			money-=w[i];
			f[u[i]][v[i]]=0;
			int flag=0;
			for(int i=1;i<=n;i++){
				if(f[i][b]==1||f[b][i]==1){
					flag=1;
					break;
				}
			}
			if(flag==0){
				money+=w[i];
				f[u[i]][v[i]]=1;
			}
		}
	}
}
int main(){
	freopen("road.in",'r',stdin);
	freopen("road.out",'w',stdout);
	cin>>n>>m>>k;
	int e,g,h;
	f[n+1][n+1]={1};
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		money+=w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(w[j+1]>=w[j]){
				e=v[j];
				g=u[j];
				h=w[j];
				v[j]=v[j+1];
				u[j]=u[j+1];
				w[j]=w[j+1];
				v[j+1]=v[j];
				u[j+1]=u[j];
				w[j+1]=w[j];
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		money+=c[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				money+=a[i][j];
			}
		}
	}
	for(int i=n;i>=1;i--){
		cl(i);
	}
	cout<<money;
	return 0;
}
