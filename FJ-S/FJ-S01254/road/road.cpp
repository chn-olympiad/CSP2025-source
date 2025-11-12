#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int n,m,k,ans=0;
long long u[N],v[N],w[N],c[12],a[12][12],hu[1000055];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		hu[i]=w[i];
	}
	int A=1;
	for(int i=1;i<=k;i++){
		cin>>c[i]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
		/*if(a[i][1]<a[i][2]&&a[i][1]<a[i][3]&&a[i][1]<a[i][4]) a[i][1]+=c[i];
		else if(a[i][2]<a[i][1]&&a[i][2]<a[i][3]&&a[i][2]<a[i][4]) a[i][2]+=c[i];
		else if(a[i][3]<a[i][1]&&a[i][3]<a[i][2]&&a[i][3]<a[i][4]) a[i][3]+=c[i];
		else if(a[i][4]<a[i][1]&&a[i][4]<a[i][2]&&a[i][4]<a[i][3]) a[i][4]+=c[i];*/
		for(int j=1;j<=4;j++){
			hu[m+A]=a[i][j]+c[i];
			A++;
		}
	}
	sort(hu+1,hu+m+A);
	for(int i=1;i<=n;i++){
		ans+=hu[i];
		//cout<<hu[i];
	}
	cout<<ans-c[1]<<'\n';
	return 0;
}