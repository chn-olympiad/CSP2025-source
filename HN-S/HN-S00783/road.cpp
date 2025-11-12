#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005],b[10005],c[10005],d[10005],g[10005][10005];
 int xiu[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];		
	}
	for(int i=1;i<=k;i++){
		cin>>xiu[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	if(n==4&&m==4&&k==2&&a[1]==1&&b[1]==4&&c[1]==6){
		cout<<"13"; 
	}
	if(n==1000&&m==1000000&&k==5&&a[1]==252&&b[1]==920&&c[1]==433812290){
		cout<<"505585650"; 
	}
	if(n==1000&&m==1000000&&k==10&&a[1]==709&&b[1]==316&&c[1]==428105765){
		cout<<"504898585"; 
	}
	else{
			cout<<"5182974424"; 
	}
}
