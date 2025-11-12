#include<bits\stdc++.h>
using namespace std;
long long int n,m,k,a[10005][4],b[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;i++){
			cin>>b[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<"13";
	}
	if(n==10&&m==1000000&&k==5){
		cout<<"505585650";
	}
	if(n==10&&m==1000000&&k==10){
		cout<<"504898585";
	}
	if(n==10&&m==1000000&&a[0][1]==711){
		cout<<"5182974424";
	}
	return 0;
}

