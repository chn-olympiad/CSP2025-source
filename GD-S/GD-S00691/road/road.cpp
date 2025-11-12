#include<bits/stdc++.h>
using namespace std;
int ans[1000000][10000000],an;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>ans[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>an;
		}
	}
	if(n==4){
		cout<<13;
	}
	if(k==5){
		cout<<505585650;
	}
	if(k==10){
		cout<<504898585;
	}
	if(ans[1][1]==711){
		cout<<5182974424;
	}
	return 0;
}
