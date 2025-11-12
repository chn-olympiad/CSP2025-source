#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10000005];
int u[10000005],v[10000005];
int w[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		if(u[i]>=v[i]){
			cin>>w[u[i]][v[i]];
			
		}
		else{
			cin>>w[v[i]][u[i]];
		}
		a[u[i]]=1;
		a[v[i]]=1;
	}
	int x;
	for(int h=0;h<k;h++){
		cin>>x;
		for(int i=1;i<=n;i++){
			if(x>=i) cin>>w[x][i];
			else cin>>w[i][x];
		}
	}
	int sum=0;
	int tmp;
	int aa,bb;
	for(int i=1;i<=n;i++){
		tmp=w[i][1];
		for(int t=1;t<=n;t++){
			if(i>=t){
				aa=i;
				bb=t;
			}else{
				aa=t;
				bb=i;
			}
			if(w[aa][bb]<tmp&&w[aa][bb]!=0) tmp=w[aa][bb];
		}
		sum+=tmp;
	}
	cout<<sum;
	return 0;
}
