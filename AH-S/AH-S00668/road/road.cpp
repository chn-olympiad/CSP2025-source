#include<bits/stdc++.h>
using namespace std;
int n,m,k,qi,u[11],v[11][1001],a[1001][1001],o,p,h,s,q[1003],ka[1004],ji[1003];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		a[i][i]=-1;
		cin>>o>>p>>h;
		a[o][p]=h;
		a[p][o]=h;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=-1){
				s=a[i][j]+s;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin>>u[i];
		for(int j=1;j<=n;j++){
		cin>>v[i][j];	
		}
	}
	cout<<s/2;
	return 0;
}   
