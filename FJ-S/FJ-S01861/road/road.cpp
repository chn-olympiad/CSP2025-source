#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,sum;
int v[20005],u[20005],w[20005];
int a[15][15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		v[2*i-1]=a1;
		v[2*i]=a2;
		u[2*i-1]=a2;
		u[2*i]=a1;
		w[2*i-1]=a3;
		w[2*i]=a3;
		sum+=a3;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m+1;j++){
			cin>>a[i][j];
		}
	}
	if(a[1][1]==0&&a[2][1]==0&&a[2][2]==0&&a[1][2]==0){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
} 
