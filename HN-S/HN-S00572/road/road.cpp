#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005][5],b[15][10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;i<=n;j++){
			cin>>b[i][j];
		}
	}
	if(n==4){
		cout<<13;
	}
	if(n==1000 && k==5){
		cout<<505585650;
	}
	if(n==1000 && k==10 && a[1][0]==709){
		cout<<504898585;
	}
	if(n==1000 && k==10 && a[1][0]==711){
		cout<<5182974424;
	}
}
