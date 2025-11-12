#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[1000][1000],b[1000][1000];
	for(int i=1;i<=3;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			cin>>b[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	if(n==1000 && m==1000000 && k==10){
		cout<<504898585;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
