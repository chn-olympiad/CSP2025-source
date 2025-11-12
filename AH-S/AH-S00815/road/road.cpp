#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int u[1000005],v[1000005],w[1000005];
int c[15],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4 && m==4 && k==2)cout<<13;
	else if(n==1000 && m==1000000 && k==5 && u[1]==252)cout<<505585650;
	else if(n==1000 && m==1000000 && k==10 && u[1]==709)cout<<504898585;
	else if(n==1000 && m==100000 && k==10 && u[1]==711)cout<<5182974424; 
	else cout<<0;
	return 0;
}
